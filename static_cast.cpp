#include<iostream>

class animal
{
    public:
        void Animal_Say(){std::cout<<"I am a animal"<<std::endl;}
};

class cat:public animal
{
    public:
        void Cat_Say(){std::cout<<"I am a cat"<<std::endl;}
};

void test1()
{
    float a=3.14;
    std::cout<<static_cast<int>(a)<<std::endl;
    std::cout<<static_cast<char>(65)<<std::endl;
}

//如果父类中没有Cat_Say方法则会内存越界，这种父类转子类则就是不安全的，如
//果能正常运行纯属运气原因(内存结构的关键区域还没有被修改，从而未导致崩溃)
void test2()
{
    animal a1;
    cat c1;

    //父类只能调用自己的方法，而子类可以调用父类的方法
    a1.Animal_Say();
    c1.Animal_Say();
    c1.Cat_Say();
    std::cout<<"--------------"<<std::endl;

    //父类指针只能指向子类对象，反之不可(父类可能不包含子类的内存布局，会内存越界)
    animal* a_ptr=&c1;

    //通过父类指针只能调用父类的方法，无法调用子类的方法(父类只有父类的方法，没有子类的方法)
    a_ptr->Animal_Say();

    //1.类型转换后再调用
    static_cast<cat*>(a_ptr)->Cat_Say();

    //2.定义子类指针接收后再调用
    cat* c_ptr=static_cast<cat*>(a_ptr);
    c_ptr->Cat_Say();

    //引用同理
    animal& a_y=c1;
    a_y.Animal_Say();
    static_cast<cat&>(a_y).Cat_Say();

    //子类转父类是安全行为
}

int main()
{
    test1();   
    test2();

    return 0;
}