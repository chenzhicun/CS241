//
// Created by Zhicun_Chen on 2019/10/12.
//

#ifndef ASSIGNMENT5_MYSORT_H
#define ASSIGNMENT5_MYSORT_H
#include "myData.h"

template <class Iterator>
void mySort(Iterator first,Iterator last)
{
    mySort(first,last,default_comparator<Iterator>());
}

template <class Iterator,class Compare>
void mySort(Iterator first,Iterator last,Compare comp)
{
    for(Iterator left(first);left!=last;left++)
    {
        for(Iterator right(left);right!=last;right++)
        {
            if(comp(*right,*left))
            {
                auto tmp_addr=(*right).addr;
                auto tmp_val=(*right).val;
                (*right).addr=(*left).addr;
                (*right).val=(*left).val;
                (*left).addr=tmp_addr;
                (*left).val=tmp_val;
            }
        }
    }
}

#endif //ASSIGNMENT5_MYSORT_H
