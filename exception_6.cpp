#include<iostream>
#include<stdexcept>
#include<new>

void GetAge(int age)
{
    if(age<0||age>100)//超出范围的异常
        throw std::out_of_range("age must between 0 and 100!");
    
    std::cout<<"age:"<<age<<std::endl;
}

char* GetNewSpace(int size)
{
    if(size<=0||size>100000000)//内存开辟异常
        throw std::bad_alloc();

    char* ptr=new char[size];
    return ptr;
}

void test1()
{
    try
    {
        GetAge(1000);
    }
    catch(std::exception& e1)
    {
        std::cout<<e1.what()<<std::endl;
    }
}

void test2()
{
    try
    {
        GetNewSpace(-200);
    }
    catch(std::exception& e1)
    {
        std::cout<<e1.what()<<std::endl;
    }
    
}

int main()
{   
    test1();
    test2();
    return 0;
}