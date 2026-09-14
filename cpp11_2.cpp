#include<iostream>

template<class... Ts>
void fun1(Ts... Args)
{
    //...
}

void Print()
{
    std::cout<<std::endl;
}

template<class T,class... Ts>
void Print(T data,Ts... datas)
{
    std::cout<<data<<" ";
    Print(datas...);
}

void test1()
{
    Print(1,"3",'A',"ABCD");
    Print(1,2);
}

template<class... Args>
void Print2(Args... args)
{
    int arr[]={(std::cout<<args<<" ",0)...};
    std::cout<<std::endl;
}

void test2()
{
    Print2(1,2,3,'W');
    Print2("hello","Say",3.14);
}

template<class... Args>
void Pirnt3(Args... args)
{
    std::forward<Args>(args)...;
    
}

int main()
{
    test1();
    test2();

    return 0;
}