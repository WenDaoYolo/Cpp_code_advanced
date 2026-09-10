#include<iostream>

int devide(int x,int y)
{
    if(y==0)
        throw y;
    return y;
}

void test1()
{
    try
    {
        int res=devide(3,0);
        std::cout<<"res:"<<res<<std::endl;
    }
    catch(int exception_1)
    {
        std::cout<<exception_1<<std::endl;
    }
    catch(char exception_2)
    {
        std::cout<<exception_2<<std::endl;
    }
}

void test4()
{
    devide(1,0);
    std::cout<<"unprocess exception..."<<std::endl;
}

void test3()
{
    test4();
    std::cout<<"unprocess exception..."<<std::endl;
}

void test2()
{
    try
    {
        test3();
    }
    catch(int exception_1)
    {
        std::cout<<exception_1<<std::endl;
    }
    std::cout<<"process exception!"<<std::endl;
}

int main()
{
    test1();
    test2();

    return 0;
}
