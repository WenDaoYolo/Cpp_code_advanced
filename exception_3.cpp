#include<iostream>

void test1() throw(int,char)
{
    //声明抛出的异常只能为int或char类型，但此时抛出了浮点型
    throw 3.14;
}

void test2() throw()
{
	//不能抛出任何异常，但此时抛出了异常
	throw 'W';
}

void test3()
{
	//可以抛出任何类型的异常
	throw 1000;
}

int main()
{
    try//尝试捕获(只有test1的会被捕获)
    {
        test1();
        test2();
        test3();
    }
    catch(...)//匹配所有捕获到的异常并处理
    {
        std::cout<<"process exception"<<std::endl;
    }
    
    //即使编译通过，但可以发现程序仍然终止了，因为抛出了未声明的异常类型
    return 0;
}