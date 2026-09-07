#include<iostream>

template<class T>
class father
{
    public:
        T t1;
    
        father(T e){ t1=e; }
};

class child:public father<int>
{
    public:
        //传参给父类，然后通过父类的构造来构造父类部分
        child(int a):father(a){ }
};

template<class T>
class animal
{
    public:
        T age;
};

template<class T1>
class Dog:public animal<int>
{
    public:
        T1 name;
        void DogRun(){};
};

template<class T1,class T2>
class cat:public animal<T2>
{
    public:
        T1 name;
        void CatRun(){};
};

int main()
{
    child c1(1);

    return 0;
}