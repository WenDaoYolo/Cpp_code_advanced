#include<iostream>

class animal
{
    public:
        virtual void Animal_Say(){std::cout<<"I am a animal"<<std::endl;}
};

class cat:public animal
{
    public:
        void Cat_Say(){std::cout<<"I am a cat"<<std::endl;}
};


//实际类型：animal* -> cat* ->转换失败
void test1()
{
    animal a1;
    cat c1;
    animal* a_ptr=&a1;

    cat* c_ptr=dynamic_cast<cat*>(a_ptr);
    
    if(c_ptr==nullptr)
        std::cout<<"cast failed"<<std::endl;
    else
        std::cout<<"cast success"<<std::endl;
}

//实际类型：cat* -> cat* ->转换成功
void test2()
{
    animal a1;
    cat c1;

    //animal*类型指针实际指向cat类的对象
    animal* a_ptr=&c1;

    cat* c_ptr=dynamic_cast<cat*>(a_ptr);
    
    if(c_ptr==nullptr)
        std::cout<<"cast failed"<<std::endl;
    else
        std::cout<<"cast success"<<std::endl;
}

//实际类型：animal& -> cat& ->转换失败
void test3()
{
    animal a1;
    cat c1;
    animal& a_ptr=a1;

    cat& c_ptr=dynamic_cast<cat&>(a_ptr);

    //抛出异常，程序会被终止，下面的代码则不会被执行
    std::cout<<"cast success"<<std::endl;
}

int main()
{
    test1();
    test2();
    test3();
    
    return 0;
}