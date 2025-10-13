#include <QApplication>
#include <QDebug>
#include <QtCore/qdebug.h>
#include <QtCore/qlogging.h>
#include <QtCore/qobject.h>
#include <QtCore/qtdeprecationdefinitions.h>
#include "counter/counter.h"


int main(int argc, char *argv[])
{
    Counter a, b;

    // 链接槽（setValue）和信号（valueChanged）
    QObject::connect(&a, &Counter::valueChanged,
                     &b,[&b](int v){
                            qDebug() << Q_FUNC_INFO << "received" << v;
                            b.setValue(v);
                     });
    // 编译期展开的宏，返回 当前函数签名字符串（带类名、参数）              
    qDebug() << Q_FUNC_INFO << "emitting from a";
    a.setValue(42);
    return 0;
}