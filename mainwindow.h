#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QMessageBox>
#include "ui_mainwindow.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
//    static void rep();


private slots:
    void on_random_button_clicked();

    void on_draw_button_clicked();

    void on_remove_button_clicked();

    void on_search_button_clicked();

    void on_add_button_clicked();

    void on_build_button_clicked();

    void on_NLR_button_clicked();

    void on_LNR_button_clicked();

    void on_LRN_button_clicked();

    void on_task_button_clicked();

    void keyPressEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;
protected:
     void paintEvent(QPaintEvent *);
};
#endif // MAINWINDOW_H
