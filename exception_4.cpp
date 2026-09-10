#include<iostream>
#include<string.h>

class MyException
{
	public:
        char* info;
		MyException(const char* str)
		{
            info=new char[64];
            strcpy(info,str);
		}
    
        ~MyException()
        {
            if(info!=NULL)
            {
                delete[] info;
                info=NULL;
            }
        }

        void GetErrorInfo(){ std::cout<<info<<std::endl;}
};

int devide(int x,int y)
{
    if(y==0)
        throw MyException("devide num is 0!");//构造一个匿名对象并抛出

    if(x>=9999)
        throw MyException("num is too big");
    return x/y;
}

void test1()
{
    try
    {
        devide(4,0);
    }
    catch(MyException& e)//定义引用接收(如果定义值接收则会发生浅拷贝，需要实现深拷贝构造)
    {
        e.GetErrorInfo();
    }
    std::cout<<"finished"<<std::endl;

    try
    {
        devide(1000000,1);
    }
    catch(MyException& e)
    {
        e.GetErrorInfo();
    }
    std::cout<<"finished"<<std::endl;
}

int main()
{
    test1();

    return 0;
}