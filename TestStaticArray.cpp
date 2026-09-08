#include "StaticArray.hpp"

template<class T>
void ShowArrayInfo(StaticArray<T>& array)
{
    std::cout<<"total size:"<<array.TotalSize();
    std::cout<<" current size:"<<array.CurSize()<<std::endl;
    std::cout<<"array data:";

    for(int i=0;i<array.CurSize();i++)
        std::cout<<array[i]<<" ";
    std::cout<<std::endl;
}

template<class T>
void CreateArray(StaticArray<T>& array)
{
    for(int i=0;i<array.TotalSize();i++)
        array[i]=i*10;
    array.SetCurSize(10);
}

void test1()
{
    StaticArray<int> arr1(10);
    StaticArray<int> arr3(10);
    CreateArray(arr1);
    
    StaticArray<int> arr2(arr1);
    arr3=arr2=arr1;
    arr3.PopBack();
    arr3.PushBack(666);

    ShowArrayInfo(arr1);
    ShowArrayInfo(arr2);
    ShowArrayInfo(arr3);
}

void test2()
{
    StaticArray<char> arr1(10);
    arr1.PushBack('W');
    arr1.PushBack('A');
    arr1.PushBack('S');
    arr1.PushBack('D');
    char tmp='P';
    arr1.PushBack(tmp);

    StaticArray<char> arr2=arr1;
    arr2.PopBack();

    ShowArrayInfo(arr1);
    ShowArrayInfo(arr2);
}

int main()
{
    test1();
    test2();

    return 0;
}