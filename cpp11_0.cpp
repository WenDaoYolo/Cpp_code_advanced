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

void ttt1(const stu& s)
{
    stu tmp1=s;                  //const&统一按左值处理，调用拷贝构造
}

void ttt2(stu&& s)
{
    stu tmp1=s;                  //虽然为&&类型，但具名变量仍是左值，调用拷贝构造
    stu tmp2=std::move(s);       //显示调用move，调用移动构造
}

void ttt3(stu tmp){}             //传值调用，根据实参的值类别调用不同的语义

//拷贝语义
void test1()
{
    stu s1(101,"zhangsan");     //构造
    stu s2(102,"lisi");         //构造
    stu s3(s1);                 //s1为左值，拷贝构造
    s2=s1;                      //s1为左值，拷贝赋值

    ttt1(s1);                   //传递左值引用
    ttt1(std::move(s3));        //传递右值引用
}

//移动语义
void test2()
{
    stu s1(101,"zhangsan");
    stu s2(102,"lisi");
    stu s3(103,"wangwu");

    stu&& p1=std::move(s1);     //转换并获取右值引用，但具名右值仍是左值
    s2=p1;                      //p1为左值，拷贝赋值
    s1=std::move(s2);           //显示调用move，移动赋值
    stu s4=std::move(s3);       //显示调用move，移动构造
    ttt2(std::move(s4));        //只能传递右值或右值引用

    if(s2.name==nullptr&&s3.name==nullptr&&s4.name==nullptr)
        std::cout<<"s2,s3,s4 is moved"<<std::endl;
}

//传值调用时，实参构造形参
void test3()
{
    stu s1(3,"www");
    ttt3(s1);                   //实参为左值，拷贝构造形参
    ttt3(std::move(s1));        //实参为右值，移动构造形参
}

int main()
{   
    test1();
    std::cout<<"------------"<<std::endl;
    test2();
    std::cout<<"------------"<<std::endl;
    test3();

    return 0;
}