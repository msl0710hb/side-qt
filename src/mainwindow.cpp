#include "mainwindow.hpp"
#include "ui_mainwindow.h"
// 测试引入自己写的类
#include "utils/StringUtils.hpp"
#include <QMessageBox>
#include <QMainWindow>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mainwindow)
{
    ui->setupUi(this);
    setWindowTitle("Qt6 + VS Code + modules");

    // 简单测试
    QString s = StringUtils::toUpper("hello macos");
    QMessageBox::information(this, "Test", s);
}

MainWindow::~MainWindow() = default;