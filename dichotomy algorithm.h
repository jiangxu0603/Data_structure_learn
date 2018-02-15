//
// Created by jiangxu on 2018/2/7.
//

#ifndef DATA_STRUCTURE_DICHOTOMY_ALGORITHM_H
#define DATA_STRUCTURE_DICHOTOMY_ALGORITHM_H

#include <stdio.h>

#define MY_SUCCESS  (0X00)
#define MY_ERROR    (0X01)
#define NOT_FOUND   (0X02)

typedef struct
{
    unsigned int position;
    unsigned int search_time;
}dichotomy_result_t;

unsigned int dichotomy_search(int const *list, unsigned int len, int item, dichotomy_result_t *result);
#endif //DATA_STRUCTURE_DICHOTOMY_ALGORITHM_H
