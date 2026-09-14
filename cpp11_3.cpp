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

template<class... Args>
void ttt1(Args... args){}

template<class... Args>
void ttt2(Args&&... args){}

void test1()
{
    stu s1(123,"111"),s2(456,"222");
    //变长参数模板发生了移动和拷贝构造
    ttt1(s1,std::move(s2));
    std::cout<<"-------------"<<std::endl;
    //万能引用没有发生构造
    ttt2(s1,std::move(s2));
}

int main()
{
    test1();
    
    return 0;
}