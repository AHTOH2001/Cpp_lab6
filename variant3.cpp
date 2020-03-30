#include "variant3.h"
Ui::MainWindow* ui;
DemonstrationClass *parent;
variant3::variant3(Ui::MainWindow* _ui,DemonstrationClass *_parent)
{
    ui = _ui;
    parent = _parent;
}
void KillChildren(MyTreap<MyPair<int,QString>>::node* Q)
{
    if (Q==NULL) return;
    parent->exist[Q->x.first] = false;
    KillChildren(Q->left);
    KillChildren(Q->right);
}
void variant3::on_task_button_clicked()
{
    MyTreap<MyPair<int,QString>>::node* Q = parent->root;
    int k = ui->line_task->text().toInt();
    if (Q!=NULL && Q->x.first==k)
    {
        parent->root=NULL;
        return;
    }
    while (true)
    {
        if (Q==NULL) throw (-1);
        if (Q->left!=NULL)
            if (Q->left->x.first==k)
            {
                KillChildren (Q->left);
                Q->left = NULL;
                return;
            }
        if (Q->right!=NULL)
            if (Q->right->x.first==k)
            {
                KillChildren (Q->right);
                Q->right = NULL;
                return;
            }

        if (Q->x.first>k) Q=Q->left;
        else
            if (Q->x.first<k) Q=Q->right;
            else
            {
                return;
            }
    }
}
