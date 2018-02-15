#include <stdio.h>
#include "stack.h"
#include "dichotomy algorithm.h"
#define LEN_INT_LIST(list) (sizeof(list) /  sizeof(int))

#include "lqueue.h"
int main()
{
    /* test stack
    printf("Hello, World!\n");
    Stack_T stack1;
    stack1 = Stack_new();
    char str1[] = "jiangxu";
    char str2[] = "I love you";
    char str3[] = "xjxjx";
    Stack_count_print(stack1);
    */

    /*
    int list[] = {5};
    int list1[] = {1, 3, 5, 7, 9, 11, 14, 17, 18, 19};
    dichotomy_result_t result;
    unsigned int status = dichotomy_search(list, LEN_INT_LIST(list), 5, &result);
    if(status == MY_SUCCESS)
        printf("The position is %d, and the search time is %d !\n", result.position, result.search_time);
    else
        printf("ERROR");
    */
    link_queue queue;
    queue = InitLQueue();
    LQueuePush(queue, 2);
    LQueuePush(queue, 14);
    LQueuePush(queue, 15);
    int val;
    LQueuePop(queue, &val);
    ShowQueue(queue);
    Destroy(queue);
    ShowQueue(queue);
}