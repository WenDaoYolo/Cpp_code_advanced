#include<iostream>
#include<exception>
#include<string.h>
#include<new>

class StrException:public std::exception
{
    public:
        char* error_info;
    public:
        StrException(const char* str) 
        {
            error_info=new char[strlen(str)+1];
            strcpy(error_info,str);
        }

        virtual const char* what() const noexcept 
        { return error_info; };

        ~StrException()
        {
            if(error_info!=NULL)
            {
                delete[] error_info;
            }
        }
};

void StrCpy(char* destination,const char* source)
{
    if(destination==NULL)
        throw StrException("destination is NULL!");
    if(source==NULL)
        throw StrException("source is NULL!");
    if(strlen(source)>10)
        throw std::bad_alloc();

    const char* find=source;
    for(int i=0;i<strlen(source)+1;i++)
        *(destination+i)=*(find+i);
}

void test1()
{
    char str[32]={0};
    try
    {
        StrCpy(str,"hello");
    }
    catch(std::exception& e1)
    {
        std::cout<<e1.what()<<std::endl;
    }
    std::cout<<str<<std::endl;
}

void test2()
{
    char str[32]={0};
    try
    {
        StrCpy(str,NULL);
    }
    catch(std::exception& e1)
    {
        std::cout<<e1.what()<<std::endl;
    }
    std::cout<<str<<std::endl;
}

void test3()
{
    char str[32]={0};
    try
    {
        StrCpy(NULL,"hello");
    }
    catch(std::exception& e1)
    {
        std::cout<<e1.what()<<std::endl;
    }
    std::cout<<str<<std::endl;
}

void test4()
{
    char str[32]={0};
    try
    {
        StrCpy(str,"12345678910");
    }
    catch(std::exception& e1)
    {
        std::cout<<e1.what()<<std::endl;
    }
    std::cout<<str<<std::endl;
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    
    return 0;
}