//
// Created by jiangxu on 2018/2/4.
//

#ifndef DATA_STRUCTURE_STACK_H
#define DATA_STRUCTURE_STACK_H
#define T Stack_T
typedef struct T *T;

T    Stack_new(void);
int  Stack_empty(T stk);
void Stack_push(T stk, void *x);
void *Stack_pop(T stk);
void Stack_free(T *stk);
void Stack_print(T stk);
void Stack_count_print(T stk);
#undef  T
#endif //DATA_STRUCTURE_STACK_H
