#include "counter.h"
#include <QtCore/qtmetamacros.h>

void Counter::setValue(int value)
{
    if(value != m_value)
    {
        m_value = value;

        // 发射信号
        emit valueChanged(value);
    }
}