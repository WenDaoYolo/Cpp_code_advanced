#include<iostream>
#include<memory>

class student
{
    public:
        int id;
    student(){ this->id=999; }
    ~student(){ std::cout<<"~student()..."<<std::endl; }
};

void test1()
{
    std::unique_ptr<student> sptr(new student);
    std::unique_ptr<student> sptr2=std::move(sptr);
    std::cout<<(*sptr2).id<<" "<<sptr2->id<<std::endl;
}

void test2()
{
    std::shared_ptr<student> sptr1(new student);
    std::cout<<sptr1.use_count()<<std::endl;
    std::shared_ptr<student> sptr2=sptr1;
    std::cout<<sptr2.use_count()<<std::endl;

    std::cout<<sptr1->id<<" "<<sptr2->id<<std::endl;
}

void test3()
{
    std::shared_ptr<student> sptr1(new student);
    std::cout<<sptr1.use_count()<<std::endl;

    std::weak_ptr<student> wptr1=sptr1;
    std::cout<<wptr1.use_count()<<std::endl;
    std::shared_ptr<student> sptr2=wptr1.lock();

    std::cout<<sptr1->id<<std::endl;
    std::cout<<sptr2->id<<std::endl;
    std::cout<<sptr2.use_count()<<std::endl;
}

class node1
{
    public:
        std::shared_ptr<node1> last;
        std::shared_ptr<node1> next;
        ~node1(){ std::cout<<"~node1()..."<<std::endl; }
};

class node2
{
    public:
        std::shared_ptr<node2> last;
        std::weak_ptr<node2> next;
        ~node2(){ std::cout<<"~node2()..."<<std::endl; }
};

//shared_ptr循环引用
void test4()
{
    std::shared_ptr<node1> n1(new node1);
    std::shared_ptr<node1> n2(new node1);

    n1->last=n2;
    n2->next=n1;
}

//weak_ptr打破循环引用
void test5()
{
    std::shared_ptr<node2> n1(new node2);
    std::shared_ptr<node2> n2(new node2);

    n1->last=n2;
    n2->next=n1;
}

int main()
{
    //test1();
    //test2();
    //test3();
    //test4();
    test5();

    return 0;
}