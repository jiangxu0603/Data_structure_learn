//
// Created by jiangxu on 2018/2/4.
//

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "stack.h"
#define T Stack_T

//#define _DEBUG
typedef struct _node{
    void *data;
    struct _node *link;
}*pNode;

struct T {
    int count;
    pNode head;
};

T Stack_new(void)
{
    T stk;
    stk = malloc(sizeof(T));
#ifdef _DEBUG
    printf("%u\n", sizeof(T));
#endif
    stk->count = 0;
    stk->head = NULL;
    return stk;
}

int Stack_empty(T stk)
{
    return stk->count == 0;
}

void Stack_push(T stk, void *x)
{
    //新建节点，并分配空间
    pNode t;
    t = malloc(sizeof(t));
    //为新建的节点赋值，指向之前的head
    t->data = x;
    t->link = stk->head;
    //head中储存最新放进的节点
    stk->head = t;
    stk->count += 1;
#ifdef _DEBUG
    printf("Push count is %d\n", stk->count);
#endif
    //printf("The node's value pushed is %s\n", (char*)stk->head->data);
}

void *Stack_pop(T stk)
{
    //如果stack为空，则返回
    if(stk->count == 0)
        return 0;
    //移除最后放入的节点
    pNode temp;
    void *x;
    temp = stk->head;
    stk->head = temp->link;
    stk->count -= 1;
#ifdef _DEBUG
    printf("Pop count is %d\n", stk->count);
#endif
    assert(stk->count >= 0);
    x = temp->data;
    free(temp);
    assert(stk);
    return x;
}

void Stack_free(T *stk)
{
    pNode t, u;
    assert(stk && *stk);
    for(t = (*stk)->head; t != NULL; t = u)
    {
        u = t->link;
        free(t);
    }
    free(*stk);
}

void Stack_print(T stk)
{
    if(stk == NULL)
    {
        printf("Please initial the stack first");
        return;
    }
    if(stk->count == 0)
    {
        printf("The stack is empty");
        return;
    }
    assert(stk != NULL);
    pNode ptr;
    ptr = stk->head;
    printf("The values in Stack is \n");
    for(int i=0; i < stk->count; i++)
    {
        printf("%s\n", (char*)ptr->data);
        ptr = ptr->link;
    }
}

void Stack_count_print(T stk)
{
    if(stk != NULL)
        printf("The element'count in stack is %d", stk->count);
    else
        printf("Please initial the stack first");
}