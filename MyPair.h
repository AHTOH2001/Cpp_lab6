#ifndef MYPAIR_H
#define MYPAIR_H

template <class T1,class T2>
struct MyPair
{
    T1 first;
    T2 second;

};
template <class T1,class T2>
bool operator>(MyPair<T1,T2> &p1,MyPair<T1,T2> &p2)
{
    return p1.first>p2.first;
}
template <class T1,class T2>
int operator<(MyPair<T1,T2>&p1,MyPair<T1,T2>&p2)
{
    return p1.first<p2.first;
}
template <class T1,class T2>
bool operator==(MyPair<T1,T2>&p1,MyPair<T1,T2>&p2)
{
    return p1.first==p2.first;
}
template <class T1,class T2>
bool operator<=(MyPair<T1,T2>&p1,MyPair<T1,T2>&p2)
{
    return p1.first<=p2.first;
}
template <class T1,class T2>
bool operator>=(MyPair<T1,T2>&p1,MyPair<T1,T2>&p2)
{
    return p1.first>=p2.first;
}


//template <class T1, class T2>
//Q_DECL_CONSTEXPR Q_INLINE_TEMPLATE bool operator<=(const QPair<T1, T2> &p1, const QPair<T1, T2> &p2)
//    Q_DECL_NOEXCEPT_EXPR(noexcept(!(p2 < p1)))
//{
//    return !(p2 < p1);
//}
#endif // MYPAIR_H
