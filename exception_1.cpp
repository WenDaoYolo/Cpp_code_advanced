#include<iostream>

int devide(int x,int y)
{
    if(y==0)
        throw y;
    if(x>100000)       //如果除数太大，则将其抛出
        throw x;
    return y;
}

void test1()
{
    try
    {
        int res=devide(3,0);
        int res2=devide(100000000,3);
        std::cout<<"res:"<<std::endl;
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
    //test2();

    return 0;
}
