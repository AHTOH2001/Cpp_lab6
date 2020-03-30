#ifndef MYTREAP_H
#define MYTREAP_H
#include <QDebug>
template <typename T>
class MyTreap
{
public:
    MyTreap()
    {

    }
    struct node
    {
        T x;
        int y;
        node *left,*right;
        node (T nx,int ny)
        {
            x = nx;
            y = ny;
            left = NULL;
            right = NULL;
        }
    };

    QPair <node*,node*> Split (T k,node* t)
    {
        if (t==NULL) return {NULL,NULL};
        if (k>t->x)
        {
            QPair<node*,node*> temp = Split(k,t->right);
            t->right = temp.first;
            return {t,temp.second};
        }
        else
        {
            QPair<node*,node*> temp = Split(k,t->left);
            t->left = temp.second;
            return {temp.first,t};
        }

    }

    node* Merge (node* t1,node* t2)
    {
        if (t1==NULL) return t2;
        if (t2==NULL) return t1;
        if (t1->y>t2->y)
        {
            t1->right = Merge(t1->right,t2);
            return t1;
        }
        else
        {
            t2->left = Merge(t1,t2->left);
            return t2;
        }

    }

    node* Insert (T k,node* t)
    {
        QPair <node*,node*> temp = Split (k,t);
        node* newNode = new node(k,rand()%560);
        return Merge(Merge(temp.first,newNode),temp.second);
    }

    node* Remove (T k,node* t)
    {
        QPair<node*,node*> temp = Split(k,t);
        node* Q = temp.second;
        node* pQ = NULL;
        if (Q->left==NULL)
            temp.second = temp.second->right;
        else
        {
            while (Q->left!=NULL)
            {
                pQ = Q;
                Q=Q->left;
            }
            pQ->left = Q->right;
        }
        //QPair<node*,node*> temp2 = Split(k+1,temp1.second);
        return Merge(temp.first,temp.second);
    }
    T Search (T k,node* t)
    {
        if (t==NULL) throw (-1);
        if (t->x>k) return Search(k,t->left);
        else
            if (t->x<k) return Search(k,t->right);
            else return t->x;
    }

private:

};
#endif // MYTREAP_H
