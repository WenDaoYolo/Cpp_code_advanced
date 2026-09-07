#include<iostream>

template<class T>
class stu
{
    public:
        static T a;
};

template<class T>
T stu<T>::a=0;

void test()
{
    stu<float> s1,s2,s3;
    stu<int> s4,s5,s6;

    s1.a=1000;
    s4.a=3.14;

    std::cout<<s1.a<<" "<<s2.a<<" "<<s3.a<<std::endl;
    std::cout<<s4.a<<" "<<s5.a<<" "<<s6.a<<std::endl;
}

int main()
{
    test();

    return 0;
}