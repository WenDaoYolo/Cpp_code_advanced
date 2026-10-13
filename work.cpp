#include<iostream>
#include<assert.h>

class my_string
{
    private:
        char* space_;
    public:
        my_string(const char* str="");
        my_string(const my_string& src);
        my_string(my_string&& src);
        ~my_string();
        
        void operator=(const my_string& src);
        void operator=(my_string&& src);
        char& operator[](int index);
        friend std::ostream& operator<<(std::ostream& os,const my_string& mys);

        bool empty();
        bool size();
};

char* my_strcpy(char* dest,const char* src)
{
    assert(dest!=NULL&&src!=NULL);
    char* res=dest;
    while((*dest++=*src++)!='\0');
    return res;
    my_string s1;
    std::cout<<s1<<std::endl;
}

void test1()
{
    char tmp[10];
    const char* str="hello";
    my_strcpy(tmp,str);
    std::cout<<tmp<<std::endl;
}

void test2()
{

}

int main()
{
    test1();

    return 0;
}