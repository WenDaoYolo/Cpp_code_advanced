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
    stu tmp=s;//左值引用，则发生拷贝构造
}

void ttt2(stu&& s)
{
    stu tmp=std::move(s);//右值引用，则发生移动构造
}

void test1()
{
    stu s1(101,"zhangsan"); //构造
    stu s2(102,"lisi");     //构造

    stu s3=s1;              //左值对象，触发拷贝构造
    s2=s1;                  //左值对象，触发拷贝赋值
    ttt1(s1);               //左值对象
    ttt1(std::move(s1));    //右值引用(但形参为const&)
}

void test2()
{
    stu s1(101,"zhangsan"); //构造
    stu s2(102,"lisi");     //构造
    stu s3(103,"sss");      //构造

    stu s4=stu(1001,"jack");//右值对象，触发移动构造
    stu s5=std::move(s1);   //右值引用，触发移动构造
    s3=s2;                  //左值对象，触发拷贝构造
    s3=std::move(s2);       //右值引用，触发移动赋值
    ttt2(std::move(s3));    //右值引用(形参也为&&)

    if(s1.name==nullptr&&s2.name==nullptr&&s3.name==nullptr)
        std::cout<<"nothing.."<<std::endl;
}

int main()
{   
    //test1();
    test2();

    return 0;
}