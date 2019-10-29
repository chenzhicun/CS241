//
// Created by Zhicun_Chen on 2019/10/21.
//

#ifndef ASSIGNMENT6_SORT_H
#define ASSIGNMENT6_SORT_H

#include <iostream>
#include <vector>
using namespace std;

class EmptyArray{};

template <typename T>
int Partition(vector<T>& A,int j,int low,int high)
{
    swap(A[low],A[j]);
    T tmp=A[low];
    do{
        while(low<high && A[high]>=tmp)
            --high;
        if(low<high)
        {
            A[low]=A[high];
            ++low;
        }
        while(low<high && A[low]<tmp)
            ++low;
        if(low<high)
        {
            A[high]=A[low];
            --high;
        }
    }while(low!=high);
    A[low]=tmp;
    return low;
}

template <typename T>
void Quicksort(vector<T>& A,int low,int high)
{
    int mid=0;
    if(low>=high) return;
    mid=Partition(A,high,low,high);
    Quicksort(A,mid+1,high);
    Quicksort(A,low,mid-1);
}

template <typename T>
void Quicksort(vector<T>& A)
{
    Quicksort(A,0,int(A.size()-1));
}

template <typename T>
T Rselect(vector<T>& A,int low,int high,int i_th)
{
    if(low==high)
        return A[low];

    int n=high-low+1;
    int p=low+rand()%n;

    int mid=Partition(A,p,low,high);
    int j=mid-low+1;
    if(j==i_th)
        return A[mid];
    if(j>i_th)
        return Rselect(A,low,mid-1,i_th);
    else
        return Rselect(A,mid+1,high,i_th-j);
}

template <typename T>
T Rselect(vector<T>& A,int i_th)
{
    return Rselect(A,0,A.size()-1,i_th);
}

template <typename T>
T Dselect(vector<T>& A,int low,int high,int i_th);

template <typename T>
T Dselect(vector<T>& A,int i_th);

template <typename T>
T Median(vector<T>& A,int low,int high)
{
    int size=high-low+1;
    for(int i=0;i<size;i++)
        for(int j=i+1;j<size;j++)
            if(A[low+i]>A[low+j])
                swap(A[low+i],A[low+j]);

    return A[low+(size/2)];
}

template <typename T>
T Dselect(vector<T>& A,int low,int high,int i_th)
{
    if(low==high)
        return A[low];

    int num=(high-low+1)/5;
    vector<T> medians;
    for(int i=0;i<num;i++)
        medians.push_back(Median(A,low+i*5,low+i*5+4));
    if(A.size()%5!=0)
    {
        medians.push_back((Median(A,low+num*5,high)));
        num++;
    }
    T pivot=Dselect(medians,medians.size()/2);
    int index;

    for(int i=0;i<A.size();++i)
    {
        if(A[i]==pivot) {index=i;break;}
    }
    int mid=Partition(A,index,low,high);
    int j=mid-low+1;
    if(j==i_th)
        return A[mid];
    if(j>i_th)
        return Dselect(A,low,mid-1,i_th);
    else
        return Dselect(A,mid+1,high,i_th-j);

}

template <typename T>
T Dselect(vector<T>& A,int i_th)
{
    return Dselect(A,0,A.size()-1,i_th);
}
#endif //ASSIGNMENT6_SORT_H
