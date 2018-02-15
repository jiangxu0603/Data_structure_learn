//
// Created by jiangxu on 2018/2/7.
//

#include <stddef.h>
#include <stdio.h>
#include "dichotomy algorithm.h"

unsigned int dichotomy_search(int const *list, unsigned int len, int item, dichotomy_result_t *result)
{
    if(len == 0 || list == NULL)
        return MY_ERROR;
    if((len == 1) && (item == list[0]))
    {
        result->search_time = 1;
        result->position = 0;
        return MY_SUCCESS;
    }
    unsigned int low = 0;
    unsigned int high = len - 1;
    result->position = (low + high) / 2;
    result->search_time =  0;
    int guess = list[result->position];
    while (low <= high)
    {
        result->search_time += 1;
        result->position = (low + high) / 2;
        if(list[result->position] == item)
            return MY_SUCCESS;
        if(list[result->position] > item)
        {
            high = result->position - 1;
        } else if(list[result->position] < item)
        {
            low = result->position + 1;
        }
    }
    return NOT_FOUND;
}