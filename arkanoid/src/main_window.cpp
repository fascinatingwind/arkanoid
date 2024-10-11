#include "main_window.h"

#include "ui_main_window.h"

#include <QRect>
#include <qnamespace.h>
#include <QObject>

#include "brick.h"

using namespace Concept;

main_window::main_window(QWidget* parent)
    : QMainWindow(parent)
{
    setup_ui();
}

main_window::~main_window()
{
    delete ui;
}

void main_window::setup_ui()
{
    ui = new Ui::MainWindow();
    ui->setupUi(this);
    items.emplace_back(QRect{1,1,20,20}, ui->plot_widget);
    items.emplace_back(Brick{1,QRectF{0, 5, 100, 40}, Qt::green}, ui->plot_widget);
}