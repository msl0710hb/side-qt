#include <memory>
#include <string>
#include <iostream>

using namespace std;

struct Widget {
    string name;
    shared_ptr<Widget> child;  // 子节点使用 shared_ptr
    weak_ptr<Widget> parent;   // 父节点使用 weak_ptr 避免循环引用

    explicit Widget(const string& n) : name(n) {
        cout << name << " constructed\n";
    }

    ~Widget() {
        cout << name << " destructed\n";
    }
};

shared_ptr<Widget> make_cycle_and_break() {
    auto dad = make_shared<Widget>("Dad");
    auto son = make_shared<Widget>("Son");

    dad->child = son;      // Dad 拥有 Son
    son->parent = dad;     // Son 知道 Dad，但不拥有（weak_ptr）

    return dad;    // 返回 weak_ptr，不会延长 Dad 的生命周期
}

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"

TEST_CASE("memory/weak_break_cycle") 
{    
    weak_ptr<Widget> w;
    {
        shared_ptr<Widget> dad = make_cycle_and_break();
        w = dad->child->parent;
        // expired() 检查 weak_ptr 是否指向一个已销毁的对象
        // CHECK_FALSE 断言条件为假时测试通过
        CHECK_FALSE(w.expired());               // Dad 还活着
        // 通过 lock() 将 weak_ptr 转换为 shared_ptr
        auto locked = w.lock();
        // REQUIRE 断言条件为真时测试通过，否则测试失败并停止
        REQUIRE(locked);                        // 确保 lock 成功
        // CHECK() 断言条件为真时测试通过
        CHECK(locked->name == "Dad");           // 验证名字
    }

    // 此时 dad 和 son 都应已销毁
    CHECK(w.expired());  // Dad 已销毁
}