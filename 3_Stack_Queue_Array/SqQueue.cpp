#include <cctype>
#include <cstdlib>
#include <iostream>
using namespace std;
#define MaxSize 50

typedef struct{
    int data[MaxSize];
    int front, rear;
}SqQueue;
void InitStack(SqQueue &Q){
    Q.front = Q.rear;
}
bool isEmpty(SqQueue Q){
    return Q.front == Q.rear;
}
bool isFull(SqQueue Q){
    return (Q.rear + 1) % MaxSize == Q.front;
}
bool Push(SqQueue &Q, int i){
    if(isFull(Q))
        return false;
    Q.data[Q.rear++] = i;
    Q.rear %= MaxSize; 
    return true;
}
bool Pop(SqQueue &Q, int &i){
    if(isEmpty(Q))
        return false;
    i = Q.data[Q.front++];
    Q.front %= MaxSize;
    return true;
}
bool GetHead(SqQueue Q, int &i){
    if(isEmpty(Q))
        return false;
    i = Q.data[Q.front];
    return true;
}