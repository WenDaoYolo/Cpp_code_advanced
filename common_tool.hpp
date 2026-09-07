#include<iostream>

template<class T>
void my_swap(T& a,T& b)
{
    T tmp=a;
    a=b;
    b=tmp;
}

template<class T>
T my_add(T a,T b)
{
    return a+b;
}