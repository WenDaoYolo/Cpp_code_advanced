#include<iostream>

class stu1
{
    public:
        int a;
        stu1(int tmp){ a=tmp;};

        //拷贝构造
        stu1(const stu1& tmp)
        {
            a=tmp.a;
            std::cout<<"stu1(const stu1&)..."<<std::endl;
        };

        //移动构造(右值直接移动构造给了形参tmp)
        stu1(stu1&& tmp)
        {
            a=tmp.a;
            std::cout<<"stu1(stu1&&)..."<<std::endl;
        };
};

class stu2
{
    public:
        int a;
        stu1 s;
        stu2(int tmp,const stu1& s1):s(s1){ a=tmp; };
        
        //拷贝构造
        stu2(const stu2& tmp):s(tmp.s)
        {
            a=tmp.a;
            std::cout<<"stu2(const stu2&)..."<<std::endl;
        };

        //移动构造(此时tmp是具名左值，想调用stu1类的移动构造则必须显示move)
        stu2(stu2&& tmp):s(std::move(tmp.s))
        {
            a=tmp.a;
            std::cout<<"stu2(stu2&&)..."<<std::endl;
        };
};

template<class... Args>
void ttt1(Args&&... args)
{
    //将传递的参数完美转发给stu2的构造函数，根据实际值类别选择移动还是构造
    stu2(std::forward<Args>(args)...);
}

template<class... Args>
void ttt2(Args... args)
{
    //将传递的参数直接转发给stu2的构造函数，此时args是具名左值则只会发生拷贝行为
    stu2(args...);
}

void test()
{
    stu1 s1(1),s2(1);
    
    ttt1(1,std::move(s1));//完美转发，传递右值引用，内部构造时则会调用移动语义
    std::cout<<"--------"<<std::endl;
    ttt2(2,std::move(s2));//不完美转发，传递右值引用但会丢失变为左值，调用拷贝语义
}

int main()
{
    test();

    return 0;
}