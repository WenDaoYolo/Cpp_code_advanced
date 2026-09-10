#include<iostream>

class e
{
    public:
        e(){ std::cout<<"e()..."<<std::endl; }
        e(const e& tmp){ std::cout<<"e(const e&)..."<<std::endl; }
        ~e(){ std::cout<<"~e()..."<<std::endl; }
};

int fun1()
{
    throw e();//构造对象并抛出，会被编译器临时存储，不会立马销毁
}

int fun2()
{
    e e1;
    e* ptr=&e1;
    throw ptr;
    //抛出栈区对象的指针(即地址)，但函数后结束对象会被销毁
    //注意，无法抛出匿名对象的地址(复习:匿名对象不能取地址)
}

void fun3()
{
    throw new e();
    //抛出堆区对象的地址，因为在堆区所以函数结束后不会销毁
}

void test1()
{
    try
    {
        fun1();
    }
    catch(e e1)//通过抛出的对象进行拷贝构造e1
    {
        std::cout<<"finished test1"<<std::endl;
    }
    //catch结束，抛出的对象和拷贝构造的对象才会销毁
}

void test2()
{
    try
    {
        fun1();
    }
    catch(e& e1)//让e1直接指向抛出的对象
    {
        std::cout<<"finished test2"<<std::endl;
    }
    //catch结束，抛出的对象才会销毁
}

void test3()
{
    try
    {
        fun2();
    }
    catch(e* e1)//e1此时指向了一个已经销毁的地址
    {
        //可以发现fun2中的对象构造完后立马就析构了
        std::cout<<"finished test3"<<std::endl;
    }
}

void test4()
{
    try
    {
        fun3();
    }
    catch(e* e1)//e1指向了抛出的堆区对象
    {
        std::cout<<"finished test3"<<std::endl;
        //需要手动释放资源
        delete e1;
    }
}

int main()
{
    test1();
    std::cout<<"----"<<std::endl;
    test2();
    std::cout<<"----"<<std::endl;
    test3();
    std::cout<<"----"<<std::endl;
    test4();

    return 0;
}