#include<iostream>

//定义两个函数指针类型
typedef void(*FUN1)(int);
typedef int(*FUN2)();

//定义两个函数
void Print(int a){ std::cout<<"Function1"<<std::endl; }
int OtherFun(){ std::cout<<"Function2"<<std::endl;return 0; }

class t1{public:int a;};
class t2{public:int b;};

void test1()
{
    FUN1 ptr1 = Print;
    FUN2 ptr2 =OtherFun;
    ptr1(3);
    ptr2();

    //转换后，让FUN2类型的函数指针指向FUN1类型的函数(则需自行保证安全性)
    FUN1 ptr3 = reinterpret_cast<FUN1>(ptr2);
    ptr3(133);
}

void test2()
{
    //强制转换类类型
    t2 t22;
    t1& ttt=reinterpret_cast<t1&>(t22);

    //强制转换指针或引用类型
    int a=30;
    int& pa=a;

    float* b1=reinterpret_cast<float*>(&a);
    float& b2=reinterpret_cast<float&>(pa);
}

int main()
{
    test1();
    test2();

    return 0;
}