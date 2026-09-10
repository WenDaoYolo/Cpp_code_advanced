#include<iostream>

class animal
{
    public:
        int* space;
        animal()
        {
            space=new int[10];
            std::cout<<"animal()..."<<std::endl;
        }

        ~animal()
        {
            delete[] space;
            std::cout<<"~animal()..."<<std::endl;
        }
};

int devide(int x,int y)
{
    animal a1;

    if(y==0)
        throw y;
    return x/y;
}

void test2()
{
    animal a2;

    devide(3,0);
}

void test1()
{
    animal a3;
    
    try
    {
        test2();
    }
    catch(int exception_1)
    {
        std::cout<<"process exception"<<std::endl;
    }
}

int main()
{
    test1();
    return 0;
}