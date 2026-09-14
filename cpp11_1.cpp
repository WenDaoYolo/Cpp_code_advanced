#include<iostream>
#include<string.h>

class stu
{
    public:
        int id;
        char* name;

    //有参构造
    stu(int e_id,const char* e_name)
    {
        this->id=e_id;
        this->name=new char[strlen(e_name)+1];
        strcpy(this->name,e_name);
        std::cout<<"stu(int,const char*)..."<<std::endl;
    }

    //拷贝构造
    stu(const stu& s1)
    {
        this->id=s1.id;
        this->name=new char[strlen(s1.name)+1];
        strcpy(this->name,s1.name);
        std::cout<<"stu(const stu&)..."<<std::endl;
    }

    //拷贝赋值
    stu& operator=(const stu& s1)
    {
        if(this==&s1)
            return *this;
        
        if(this->name!=nullptr)
        {
            delete[] this->name;
            this->name=nullptr;
        }
        
        this->name=new char[strlen(s1.name)+1];
        strcpy(this->name,s1.name);
        this->id=s1.id;
        std::cout<<"stu& operator=(const stu&)..."<<std::endl;

        return *this;
    }

    //移动构造
    stu(stu&& s1)
    {
        this->id=s1.id;
        this->name=s1.name;
        s1.name=nullptr;//转移源对象的资源，指针则需要置空
        std::cout<<"stu(stu&&)..."<<std::endl;
    }

    //移动赋值
    stu& operator=(stu&& s1)
    {
        if(this==&s1)
            return *this;
        if(this->name!=nullptr)
            delete[] this->name;
        
        this->name=s1.name;
        this->id=s1.id;
        s1.name=nullptr;
        std::cout<<"stu& operator=(stu&&)..."<<std::endl;

        return *this;
    }

    //析构
    ~stu()
    {
        if(this->name!=nullptr)
        {
            delete[] this->name;
            this->name=nullptr;
        }
        std::cout<<"~stu()..."<<std::endl;
    }
};


stu ttt1(int age)
{
    if(age==0)
        throw stu(16,"ccc");//拷贝消除，直接在异常存储区构造

    return stu(15,"www");   //拷贝消除，直接在接收对象上构造
}

void test1()
{
    stu s1=stu(14,"zzz");   //拷贝消除，直接在s1上构造
    stu s2=ttt1(1);
    
    try
    {
        ttt1(0);
    }
    catch(...){}
}

void ttt2(stu s1){}
stu ttt3()
{
    stu tmp(33,"ww");
    return tmp;                       //具名对象返回时会当右值处理
};

//匿名对象可能触发拷贝或移动语义
void test2()
{   
    ttt2(stu(13,"ww"));               //这里发生了拷贝消除，匿名对象直接在形参上进行构造    
    ttt2(std::move(stu(13,"ww")));    //这里没有发生拷贝消除，先构造匿名对象，再移动构造
}


void test3()
{
    stu t=ttt3();                     //这里没有发生移动构造，则说明发生了NRVO
}

int main()
{
    test1();
    std::cout<<"---------"<<std::endl;
    test2();
    std::cout<<"---------"<<std::endl;
    test3();

    return 0;
}