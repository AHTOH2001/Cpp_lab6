#include "mainwindow.h"
#include <demonstrationclass.h>
#include <variant3.h>
DemonstrationClass* demclass;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1244,891);
    demclass = new DemonstrationClass(ui,this);


    //demclass->ui = &ui;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_random_button_clicked()
{
    demclass->on_random_button_clicked();
}

void MainWindow::on_draw_button_clicked()
{
    demclass->on_draw_button_clicked();
}

void MainWindow::on_remove_button_clicked()
{
    demclass->on_remove_button_clicked();
}
void MainWindow::on_search_button_clicked()
{
    demclass->on_search_button_clicked();
}

void MainWindow::on_add_button_clicked()
{
    demclass->on_add_button_clicked();
}

void MainWindow::on_build_button_clicked()
{
    demclass->on_build_button_clicked();
}

void MainWindow::on_NLR_button_clicked()
{
    demclass->on_NLR_button_clicked();
}

void MainWindow::on_LNR_button_clicked()
{
    demclass->on_LNR_button_clicked();
}

void MainWindow::on_LRN_button_clicked()
{
    demclass->on_LRN_button_clicked();
}

void MainWindow::on_task_button_clicked()
{
    demclass->on_task_button_clicked();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    demclass->paintEvent(event);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    demclass->keyPressEvent(event);
}

//void MainWindow::rep()
//{
//    //repaint();
//}
