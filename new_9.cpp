#include<iostream>
#include<string>

class stu
{
    public:
        int id;
    
        stu(int id){this->id=id;};
        ~stu(){};
};

//字符串转换
void test1()
{
    int s=atoi("123");
    std::cout<<s<<std::endl;

    std::string s1="123";
    int res=std::stoi(s1);
    std::cout<<res<<std::endl;
}

void test11()
{
	//开辟原始堆区内存
	int* ptr1=static_cast<int*>(operator new(sizeof(int)));
	stu* ptr2=static_cast<stu*>(operator new(sizeof(stu)));
	
	//赋值
	*ptr1=100;
	ptr2->id=101;
	
    std::cout<<*ptr1<<" "<<ptr2->id<<std::endl;
    ptr2->~stu();

	//调用对应的销毁方式：opeartor new/new[]->operator delete/delete[]
	operator delete(ptr1);
    operator delete(ptr2);
}

void test2()
{
    //堆区原始内存
    void* ptr1=operator new(sizeof(int));
    void* ptr2=operator new(sizeof(stu));

    //定位new构造基本类型数据和类对象
    int* ptr3=new(ptr1) int(3);
    stu* ptr4=new(ptr2) stu(101);
    std::cout<<"int:"<<*ptr3<<" object:"<<ptr4->id<<std::endl;
    
    //如果类对象中有动态资源，需要手动调用析构(建议无论是否有都调用)
    ptr4->~stu();
    
    //调用对应的销毁方式：opeartor new/new[]->operator delete/delete[]
    operator delete(ptr1);
    operator delete(ptr2);
}

void test3()
{
    //栈区内存
    char arry1[20];
    
    //构造int数据
    int* ptr1=new(arry1) int(4);
    //在int数据的后面构造类对象(偏移四个字节，类对象+int<该内存)
    stu* ptr2=new(arry1+4) stu(123);

    std::cout<<*ptr1<<" "<<ptr2->id<<std::endl;
    ptr2->~stu();
}

int main()
{
    test1();
    test11();
    test2();
    test3();

    return 0;
}