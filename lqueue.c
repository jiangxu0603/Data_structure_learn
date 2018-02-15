//
// Created by jiangxu on 2018/2/14.
//
#include <stdio.h>
#include <stddef.h>
#include <assert.h>
#include <stdlib.h>
#include "lqueue.h"

#define LQUEUEMAXLENGTH 500

typedef struct _L_qnode
{
    int data;
    struct _L_qnode *next;
}L_qnode;

typedef struct _LQueue
{
    int length;
    L_qnode *front;
    L_qnode *rear;
}*link_queue;

link_queue InitLQueue()
{
    L_qnode *empty_head = BuyNode(0);
    link_queue pQueue;
    pQueue = malloc(sizeof(struct _LQueue));
    pQueue->front = empty_head;
    pQueue->rear = empty_head;
    return pQueue;
}

L_qnode* BuyNode(int val)                //从堆中申请一个节点的内存空间
{
    L_qnode *pTmp = (L_qnode*)malloc(sizeof(L_qnode));
    assert(pTmp != NULL);
    pTmp->data = val;
    pTmp->next = NULL;
    return pTmp;
}

void LQueuePush(link_queue pQueue, int val)
{
    if(pQueue->length >= LQUEUEMAXLENGTH)
    {
        printf("out of max");
        return;
    }
    L_qnode *pCur = (L_qnode*)malloc(sizeof(L_qnode));
    pCur->data = val;
    pCur->next = NULL;
    pQueue->rear->next = pCur;
    pQueue->rear = pCur;
    pQueue->length += 1;
}

bool LQueuePop(link_queue pQueue, int *rtval)     //出队，从队首(front)出
{
    if((NULL == pQueue) || (pQueue->rear == pQueue->front))
        return false;
    L_qnode *Tmp = pQueue->front;
    pQueue->front = pQueue->front->next;
    *rtval = pQueue->front->data;
    free(Tmp);
    pQueue->length -= 1;
    assert(pQueue->length > 0);
    return true;
}

int GetCQueueLen(link_queue pQueue)
{
    int count = 0;
    L_qnode *ptr = pQueue->front;
    while(ptr!=NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

bool IsEmpty(link_queue pQueue)             //队列为空则返回true
{
    return pQueue->front == pQueue->rear;
}

bool GetFront(link_queue pQueue, int *rtval) //获取队首元素
{
    if(pQueue->front == pQueue->rear)
        return false;
    *rtval = pQueue->front->data;
    return true;
}


void Destroy(link_queue pQueue)             //销毁队列(释放所有节点的内存空间)
{
    L_qnode *ptr = pQueue->front;
    pQueue->front = pQueue->front->next;
    while (ptr != NULL)
    {
        free(ptr);
        ptr = pQueue->front;
        if(pQueue->front == pQueue->rear)
        {
            return;
        }
        pQueue->front = pQueue->front->next;
    }
}

void ShowQueue(link_queue pQueue)
{
    if(pQueue->front == pQueue->rear)
    {
        printf("The queue is empty");
        return;
    }
    printf("The node in queue is \n");
    L_qnode *pnode = pQueue->front->next;
    while (pnode != NULL)
    {
        printf("%d\n", pnode->data);
        pnode = pnode->next;
    }
}