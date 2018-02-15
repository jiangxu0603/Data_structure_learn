//
// Created by jiangxu on 2018/2/14.
//

#ifndef DATA_STRUCTURE_QUEUE_H
#define DATA_STRUCTURE_QUEUE_H

#include <stdbool.h>

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

link_queue InitLQueue(); //初始化队列
L_qnode* BuyNode(int val);                //从堆中申请一个节点的内存空间
void LQueuePush(link_queue pQueue, int val);       //入队，从队尾(rear)入
bool LQueuePop(link_queue pQueue, int *rtval);     //出队，从队首(front)出
int GetCQueueLen(link_queue pQueue);         //获取队列长度
void ShowQueue(const link_queue pQueue);           //输出队列所有元素
bool IsEmpty(link_queue pQueue);             //队列为空则返回true
bool GetFront(link_queue pQueue, int *rtval); //获取队首元素
void Destroy(link_queue pQueue);             //销毁队列(释放所有节点的内存空间)

#endif //DATA_STRUCTURE_QUEUE_H
