#include<iostream>

class C
{
    public:
        int a;
        C(){a=100;}
};

void test1()
{
    C c1;
    const C* ptr_1=&c1;
    const C& index_1=c1;
    
    C* c2=const_cast<C*>(ptr_1);
    C& c3=const_cast<C&>(index_1);
    c2->a=999;
    c3.a=666;

    std::cout<<c1.a<<" "<<c2->a<<" "<<c3.a<<std::endl;
}

void test2()
{
    const int a=30;
    int& b=const_cast<int&>(a);
    b=333;
    //a=321;

    int a1=333;
    const int& b1=const_cast<const int&>(a1);
    std::cout<<a<<" "<<b<<std::endl;
}

int main()
{
    test1();
    test2();

    return 0;
}