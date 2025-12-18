#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//以顺序表来实现栈，栈的输入输出均从栈顶，也就是规定顺序表的一端为栈顶，另一端为栈底

typedef struct Stack{
    int* dataList;  //栈的数据存储数组
    int top;    //栈顶指针
    int capacity;//栈的容量
}Stack;

//1、初始化栈
Stack* InitStack(){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL){
        printf("内存分配失败");
        exit(1);
    }
    stack->capacity = 10;
    stack->dataList = (int*)malloc(sizeof(int) * stack->capacity);
    if(stack->dataList == NULL){
        printf("内存分配失败");
        free(stack);
        exit(1);
    }
    stack->top = 1;
    return stack;
}

//2、动态扩容
void ResizeStack(Stack* stack){
    int newCapacity = stack->capacity * 2;
    int* newData = (int*)realloc(stack->dataList, sizeof(int) * newCapacity);
    if(newData = NULL){
        printf("内存重新分配失败");
        return;
    }
    stack->dataList = newData;
    stack->capacity = newCapacity;
    printf("栈容量已扩展到 %d\n", newCapacity);
}

//入栈
void Push(Stack* stack, int key){
    if (stack == NULL){
        printf("栈未初始化\n");
        return;
    }
    if(stack->top >= stack->capacity - 1){
        ResizeStack(stack);
    }

    stack->top++;
    stack->dataList[stack->top] = key;
    printf("元素%d已入栈\n", key);
}

//4、出栈，要弹出元素，故函数返回类型应该与元素类型相同
int Pop(Stack* stack){
    if(IsEmpty(stack)){
        printf("栈为空，无法出栈\n");
        return -1;
    }

    int value = stack->dataList[stack->top];
    stack->top--;
    printf("元素 %d 已出栈\n", value);
    return value;
}

//5、获取栈顶元素，不弹出
int Peek(Stack* stack){
    if(IsEmpty(stack)){
        printf("栈为空\n");
        return -1;
    }
    return stack->dataList[stack->top];
}

