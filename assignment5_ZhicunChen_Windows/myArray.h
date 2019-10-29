//
// Created by Zhicun_Chen on 2019/10/12.
//

#ifndef ASSIGNMENT5_MYARRAY_H
#define ASSIGNMENT5_MYARRAY_H
#include<iostream>

using namespace std;

template<typename Elem>
class myArray
{
private:
    Elem* data;
    int sizeNum;
    int capacityNum;
    void doubleSpace();
    void halfSpace();

public:
    class iterator;

    void push_back(const Elem& v);
    void pop_back();

    iterator begin();
    iterator end();

    int size();
    int capacity();
    int* getSize(){return &sizeNum;}

    Elem& operator[](const int i);
    myArray& operator=(const myArray& A);

    myArray();
    ~myArray();
};

template <typename Elem>
void myArray<Elem>::doubleSpace()
{
    Elem *tmp=data;

    capacityNum*=2;
    data=new Elem[capacityNum];
    for(int i=0;i<sizeNum;i++)
        data[i]=tmp[i];
    delete[] tmp;
}

template <typename Elem>
void myArray<Elem>::halfSpace()
{
    Elem *tmp=data;

    capacityNum/=2;
    data=new Elem[capacityNum];
    for(int i=0;i<sizeNum;i++)
        data[i]=tmp[i];
    delete[] tmp;
}

template <typename Elem>
void myArray<Elem>::push_back(const Elem& v)
{
    if(sizeNum==capacityNum)
        doubleSpace();
    data[sizeNum]=v;
    ++sizeNum;
}

template <typename Elem>
void myArray<Elem>::pop_back()
{
    if(sizeNum==0)
    {
        cerr<<"No element can be popped.";
        exit(1);
    }
    else
        sizeNum--;
    if(sizeNum<capacityNum/41)
        halfSpace();
}

template <typename Elem>
int myArray<Elem>::size() {return sizeNum;}

template <typename Elem>
int myArray<Elem>::capacity() {return capacityNum;}

template <typename Elem>
class myArray<Elem>::iterator
{
private:
    myArray<Elem>* pMyArray;
    int curr;
public:
    iterator(iterator const &a)
    {
        pMyArray=a.pMyArray;
        curr=a.curr;
    }
    iterator(myArray<Elem>* arr,int i)
    {
        pMyArray=arr;
        curr=i;
    }
    Elem& operator*()
    {
        return (*pMyArray)[curr];
    }
    iterator& operator++(int)
    {
        curr++;
        return *this;
    }
    iterator& operator--(int)
    {
        curr--;
        return *this;
    }
    bool operator==(const iterator& that)
    {
        return (pMyArray==that.pMyArray&&curr==that.curr);
    }
    bool operator!=(const iterator& that)
    {
        return !(*this==that);//this是个位置，必须加上*才是iterator和iterator的比较，不然是内存位置和iterator的比较
    }
//    iterator& operator=(const iterator &that)
//    {
//        curr=that.curr;
//        pMyArray=that.pMyArray;
//        return *this;
//    }这里好像有一点点问题欸
};

template <typename Elem>
typename myArray<Elem>::iterator myArray<Elem>::begin()
{
    return iterator(this,0);
}

template <typename Elem>
typename myArray<Elem>::iterator myArray<Elem>::end()
{
    return iterator(this,sizeNum);//这里到底是最后一个还是最后一个的后一个？
}

template <typename Elem>
Elem& myArray<Elem>::operator[](const int i)
{
    if(i<0)
    {
        cerr<<"Iterator is out of range.";
        exit(1);
    }
    if(i>sizeNum)
    {
        cerr<<"Iterator is out of range.";
        exit(1);
    }
    return data[i];
}

template <typename Elem>
myArray<Elem>& myArray<Elem>::operator=(const myArray &A)
{
    delete[] data;

    sizeNum=A.sizeNum;
    capacityNum=A.capacityNum;

    data=new Elem[capacityNum];

    for(int i=0;i<sizeNum;i++)
    {
        data[i]=A.data[i];
    }

    return *this;
}

template <typename Elem>
myArray<Elem>::myArray()
{
    sizeNum=0;
    capacityNum=10;
    data=new Elem[capacityNum];
}

template <typename Elem>
myArray<Elem>::~myArray()
{
    capacityNum=0;
    sizeNum=0;
    delete[] data;
}

#endif //ASSIGNMENT5_MYARRAY_H
