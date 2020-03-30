#include "demonstrationclass.h"
//#include "ui_mainwindow.h"
#include <variant3.h>
MyTreap<MyPair<int,QString>> tree;
variant3* var3;
DemonstrationClass::DemonstrationClass(Ui::MainWindow* _ui,MainWindow *_parent): QWidget()
{
    //SomeMethod(parent);
    //parent->ui->
    //(static_cast<MainWindow*>(this->parent()))->ui->tableWidget->clear();
    QTime now = QTime::currentTime();
    parent = _parent;
    ui = _ui;
    srand(now.msec());
    ui->tableWidget->setHorizontalHeaderLabels({"Ключ","Информация"});
    ui->treeWidget->setHeaderLabel("TreeVisualizer");
    var3 = new variant3(ui,this);
}
DemonstrationClass::~DemonstrationClass()
{

}
QStringList str = {"суровый","важный","структурный","дипломатический","таможенный","глупый","доступный","огромный","промышленный","тогдашний","тепловой","студенческий"};
void DemonstrationClass::on_random_button_clicked()
{
    int n = ui->line_amount->text().toInt(),p = 0;
    if (n==0) n = rand()%12+3;
    //    int n = 5,p=0;
    MyPair<int,QString> mas[100];
    for (int i = 0;i<n;i++)
    {
        mas[i].first = p + rand()%5+1;
        p = mas[i].first;
        mas[i].second = str[rand()%str.length()];
    }
    for (int i = 0;i<n;i++)
    {
        int p1 = rand()%n;
        int p2 = rand()%n;
        MyPair<int,QString> x = mas[p1];
        mas[p1] = mas[p2];
        mas[p2] = x;
    }

    ui->tableWidget->clear();
    ui->tableWidget->setHorizontalHeaderLabels({"Ключ","Информация"});
    for (int i = 0;i<n;i++)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(mas[i].first)));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(mas[i].second));
    }
}

MyTreap<MyPair<int,QString>>::node* mas[1000];
int max,k;
QTreeWidgetItem* visualRoot;
void DemonstrationClass::rec(int p,MyTreap<MyPair<int,QString>>::node* t,QTreeWidgetItem* prev)
{
    if (t!=NULL)
    {
        mas[k] = t;
        k++;
    }
    if (t->x.first>max) max = t->x.first;
    QTreeWidgetItem* x = new QTreeWidgetItem();
    x->setText(0,QString::number(t->x.first));
    prev->addChild(x);
    if (t->left!=NULL)
        rec (p*2,t->left,x);
    if (t->right!=NULL)
        rec (p*2+1,t->right,x);
}
void DemonstrationClass::on_draw_button_clicked()
{
    ui->treeWidget->clear();
    ui->treeWidget->setHeaderLabel("TreeVisualizer");
    visualRoot = new QTreeWidgetItem();
    max = 0;
    k = 0;
    if (root==NULL) return;
    rec(1,root,visualRoot);
    if (max>300) max = 300;
    ui->treeWidget->addTopLevelItem(visualRoot);
    paint = true;
    parent->repaint();

}

void DemonstrationClass::on_remove_button_clicked()
{
    if (ui->line_remove->text()=="") return;
    if (!exist[ui->line_remove->text().toInt()])
    {
        QMessageBox::critical(parent," ","Error");
        return;
    }
    exist[ui->line_remove->text().toInt()] = false;
    root = tree.Remove({ui->line_remove->text().toInt(),""},root);
    QMessageBox::information(parent,"Well done","Successfully removed node");
}

void DemonstrationClass::on_search_button_clicked()
{
    try {
        MyPair<int,QString> temp = tree.Search({ui->line_search->text().toInt(),""},root);
        QMessageBox::information(parent,"Well done",temp.second);
    }
    catch (int) {
        QMessageBox::critical(parent," ","Error");
    }
}


void DemonstrationClass::on_add_button_clicked()
{
    if (ui->line_add_1->text()=="") return;
    if (exist[ui->line_add_1->text().toInt()])
    {
        QMessageBox::critical(parent," ","Error");
        return;
    }
    exist[ui->line_add_1->text().toInt()] = true;
    root = tree.Insert({ui->line_add_1->text().toInt(),ui->line_add_2->text()},root);
    QMessageBox::information(parent,"Well done","Successfully add to tree");
}

void DemonstrationClass::on_build_button_clicked()
{
    int i = 0;
    root = NULL;
    for (int i = 0;i<1000;i++)
        exist[i] = false;
    while (ui->tableWidget->item(i,0)!=NULL && ui->tableWidget->item(i,1)!=NULL)
    {
        if (exist[ui->tableWidget->item(i,0)->text().toInt()] || ui->tableWidget->item(i,0)->text()=="")
        {
            root = NULL;
            QMessageBox::critical(parent," ","Error");
            return;
        }
        exist[ui->tableWidget->item(i,0)->text().toInt()] = true;
        root=tree.Insert({ui->tableWidget->item(i,0)->text().toInt(),ui->tableWidget->item(i,1)->text()},root);
        i++;
    }
    QMessageBox::information(parent,"Well done","Successfully build tree");
}
int u = 0;
void DemonstrationClass::AddTable(MyPair<int,QString> value)
{
    ui->tableWidget->setItem(u,0,new QTableWidgetItem(QString::number(value.first)));
    ui->tableWidget->setItem(u,1,new QTableWidgetItem(value.second));
    u++;
}
void DemonstrationClass::NLR(MyTreap<MyPair<int,QString>>::node* Q)
{
    if (Q==NULL) return;
    AddTable(Q->x);
    NLR(Q->left);
    NLR(Q->right);
}
void DemonstrationClass::on_NLR_button_clicked()
{
    u = 0;
    ui->tableWidget->clear();
    ui->tableWidget->setHorizontalHeaderLabels({"Ключ","Информация"});
    NLR(root);
}

void DemonstrationClass::LNR(MyTreap<MyPair<int,QString>>::node* Q)
{
    if (Q==NULL) return;
    LNR(Q->left);
    AddTable(Q->x);
    LNR(Q->right);
}
void DemonstrationClass::on_LNR_button_clicked()
{
    u = 0;
    ui->tableWidget->clear();
    ui->tableWidget->setHorizontalHeaderLabels({"Ключ","Информация"});
    LNR(root);
}

void DemonstrationClass::LRN(MyTreap<MyPair<int,QString>>::node* Q)
{
    if (Q==NULL) return;
    LRN(Q->left);
    LRN(Q->right);
    AddTable(Q->x);
}
void DemonstrationClass::on_LRN_button_clicked()
{
    u = 0;
    ui->tableWidget->clear();
    ui->tableWidget->setHorizontalHeaderLabels({"Ключ","Информация"});
    LRN(root);
}

void DemonstrationClass::on_task_button_clicked()
{
    try{
        var3->on_task_button_clicked();
    }
    catch (int) {
        QMessageBox::critical(parent," ","Error");
        return;
    }
    QMessageBox::information(parent,"Well done","Successfully killed child");
}

void DemonstrationClass::paintEvent(QPaintEvent *)
{
    if (paint)
    {
        paint = false;
        QPainter painter(parent);

        //painter.setFont(QFont("Arial", 30));
        for (int i = 0;i<k;i++)
        {
            painter.setPen(Qt::blue);
            if (mas[i]->left!=NULL)
                painter.drawLine(590+mas[i]->x.first*(600/max)+40,830-mas[i]->y+20,590+mas[i]->left->x.first*(600/max)+40,830-mas[i]->left->y+20);
            if (mas[i]->right!=NULL)
                painter.drawLine(590+mas[i]->x.first*(600/max)+40,830-mas[i]->y+20,590+mas[i]->right->x.first*(600/max)+40,830-mas[i]->right->y+20);
            if (i==0) painter.setPen(Qt::red);
            painter.setBrush(Qt::SolidPattern);
            painter.drawEllipse(590+mas[i]->x.first*(600/max)+30,830-mas[i]->y+10,20,20);
            //if (i==0) painter.setPen(Qt::blue);
            /*else*/ painter.setPen(Qt::red);
            painter.drawText(590+mas[i]->x.first*(600/max),830-mas[i]->y,80,40,Qt::AlignCenter,QString::number(mas[i]->x.first));
        }

    }

    //    i++;
    //    qDebug() << "paintEvent " << i;
    //painter.drawRect(rand()%1000,400,600,100);
    //painter.drawRect(400,400,100,600);
    //    }
}

void DemonstrationClass::keyPressEvent(QKeyEvent *event)
{
    if (event->key()==Qt::Key_D)
        on_draw_button_clicked();
    if (event->key()==Qt::Key_B)
        on_build_button_clicked();
}












