### counter.h
- 定义 Counter 类，继承自 QObject
- Q_OBJECT 启用 Qt 元对象系统
- 实现 Counter::setValue(int valude)

### QDebug
- Q_FUNC_INFO:编译期展开的宏，返回 当前函数签名字符串（带类名、参数）