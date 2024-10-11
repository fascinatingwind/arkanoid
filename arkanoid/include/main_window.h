#pragma once

#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QWidget>

namespace Ui
{
    class MainWindow;
}

class main_window : public QMainWindow
{
    Q_OBJECT
public:

    explicit main_window(QWidget* parent = nullptr);
    ~main_window();

private:
    Ui::MainWindow* ui = nullptr;
    void setup_ui();
};

#endif