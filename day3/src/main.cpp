#include <QApplication>
#include <QtCore/qobject.h>
#include "counter/counter.h"


int main(int argc, char *argv[])
{
    Counter a, b;

    // 链接槽（setValue）和信号（valueChanged）
    QObject::connect(&a, &Counter::valueChanged,
                     &b, &Counter::setValue);
    a.setValue(12); // a.value() 变为 12, b.value() 变为 12
    a.setValue(48); // a.value() 变为 48, b.value() 变为 48
    
    return 0;
}