#include <cstddef>
#include <iostream>
using namespace std;

typedef struct LinkNode{
    int data;
    LinkNode * next;
}LinkNode;
typedef struct LinkQueue{
    LinkNode * front;
    LinkNode * rear;
}*LinkQueue;
void InitQueue(LinkQueue &Q){
    Q->front = Q->rear = new LinkNode();
    Q->front->next = NULL;
}
bool isEmpty(LinkQueue Q){
    return Q->front == Q->rear;
}
bool EnQueue(LinkQueue &Q, int i){
    LinkNode *p = new LinkNode();
    p->data = i;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
    return true;
}
bool DeQueue(LinkQueue &Q, int &i){
    if(isEmpty(Q))
        return false;
    LinkNode *p = Q->front;
    i = p->data;
    Q->front = p->next;
    delete p;
    return true;
}
bool GetTop(LinkQueue Q, int &i){
    if(isEmpty(Q))
        return false;
    i = Q->front->data;
    return true;
}