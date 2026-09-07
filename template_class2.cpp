#include<iostream>
#include<string>

template<class T1>
class animal
{
    public:
        T1 age;

        animal(T1 t){age=t;}
        
        template<class t>
        friend std::ostream& operator<<(std::ostream& os,animal<t>& a);

        friend std::istream& operator>>(std::istream& os,animal<T1>& a)
        {
            os>>a.age;
            return os;
        }
};

template<class t>
std::ostream& operator<<(std::ostream& os,animal<t>& a)
{
    os<<a.age<<std::endl;
    return os;
}

int main()
{
    animal<int> dog(13);
    std::cin>>dog;
    std::cout<<dog;

    return 0;
}