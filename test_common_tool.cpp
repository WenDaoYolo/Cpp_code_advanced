#include "common_tool.hpp"

void test()
{
    int a=10,b=100;
    char a1='a',b1='b';
    
    my_swap(a,b);
    my_swap(a1,b1);
    int c=my_add<int>(3,4);
    float c1=my_add<float>(3.14,3.15);

    std::cout<<a<<" "<<b<<std::endl;
    std::cout<<a1<<" "<<b1<<std::endl;
    std::cout<<c<<" "<<c1<<std::endl;
}

int main()
{
    test();

    return 0;
}