#ifndef DEMONSTRATIONCLASS_H
#define DEMONSTRATIONCLASS_H

#include "mainwindow.h"
#include <QTime>
#include <QButtonGroup>
#include <QObject>
#include <QtGui>
#include <QtCore>
#include <QPainter>
#include <QPaintEvent>
#include <QKeyEvent>
#include <QBrush>
//#include <QMessageBox>
#include <MyTreap.h>
#include <MyPair.h>
class DemonstrationClass: public QWidget
{
    // Q_OBJECT
public:
    DemonstrationClass(Ui::MainWindow* _ui,MainWindow *_parent);


    ~DemonstrationClass();

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

    MyTreap<MyPair<int,QString>>::node* root = NULL;

    bool paint = false;
    void paintEvent(QPaintEvent *);
    bool exist[1000] = {false};
private:
    void AddTable(MyPair<int,QString> value);
    void NLR(MyTreap<MyPair<int,QString>>::node* Q);
    void LNR(MyTreap<MyPair<int,QString>>::node* Q);
    void LRN(MyTreap<MyPair<int,QString>>::node* Q);
    void rec(int p,MyTreap<MyPair<int,QString>>::node* t,QTreeWidgetItem* prev);

    Ui::MainWindow* ui;
    MainWindow *parent;

};

#endif // DEMONSTRATIONCLASS_H
