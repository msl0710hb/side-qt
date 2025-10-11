#pragma once
#include <QObject>

class Counter : public QObject
{
    Q_OBJECT

public:
    Counter(){ m_value = 0;}  // 构造函数

    int value() const{return m_value;}

public slots:
    void setValue(int valued);

signals:
        void valueChanged(int newValue);

private:
    int m_value;

};