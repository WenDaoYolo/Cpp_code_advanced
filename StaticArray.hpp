#include<iostream>
#include<memory.h>

template<class T>
class StaticArray
{
    private:
        T* m_space;
        int m_cur_size,m_total_size;
    public:
        StaticArray(int t_size):m_total_size(t_size),m_cur_size(0)
        {
            m_space=new T[m_total_size];
            memset(m_space,0,m_total_size*sizeof(T));
        }

        bool IsEmpty()
        {
            if(m_total_size==0)
                return true;
            return false;
        }

        bool IsFull()
        {
            if(m_total_size==m_cur_size)
                return true;
            return false;
        }

        StaticArray(const StaticArray<T>& array)
        {
            m_total_size=array.m_total_size;
            m_cur_size=array.m_cur_size;
            m_space=new T[m_total_size];
            memcpy(this->m_space,array.m_space,m_total_size*sizeof(T));
        }

        ~StaticArray()
        {
            if(!IsEmpty())
            {
                delete[] m_space;
                m_space=nullptr;
            }
        }

        void PushBack(T&& e)
        {
            if(IsFull())
                return;

            m_space[m_cur_size]=e;
            m_cur_size++;
        }

        void PushBack(T& e)
        {
            if(IsFull())
                return;

            m_space[m_cur_size]=e;
            m_cur_size++;
        }

        void PopBack()
        {
            if(IsEmpty())
                return;

            m_cur_size--;
        }

        StaticArray<T>& operator=(const StaticArray<T>& array)
        {
            m_total_size=array.m_total_size;
            m_cur_size=array.m_cur_size;
            m_space=new T[m_total_size];
            memcpy(this->m_space,array.m_space,m_total_size*sizeof(T));

            return *this;
        }

        T& operator[](int index){ return m_space[index]; }
        int CurSize(){ return m_cur_size; }
        int TotalSize(){ return m_total_size; }
        void SetCurSize(int len){ m_cur_size=len; }
};