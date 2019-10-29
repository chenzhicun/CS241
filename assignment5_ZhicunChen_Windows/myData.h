//
// Created by Zhicun_Chen on 2019/10/12.
//

#ifndef ASSIGNMENT5_MYDATA_H
#define ASSIGNMENT5_MYDATA_H

template <typename T>
struct myData
{
    T val;
    myData<T>* addr;

    myData<T>(T a)
    {
        val=a;
        addr=this;
    }
    myData<T>()
    {
        addr=this;
    }
};

template <typename T>
struct Cmp_by_val
{
    bool operator()(myData<T> a,myData<T> b)
    {
        return a.val<b.val;
    }
};

template <typename T>
struct Cmp_by_addr
{
    bool operator()(myData<T> a,myData<T> b)
    {
        return a.addr<b.addr;
    }
};

template <typename Iterator>
struct default_comparator
{
    bool operator()(const Iterator& a,const Iterator& b){
        return *a<*b;
    }
};
#endif //ASSIGNMENT5_MYDATA_H
