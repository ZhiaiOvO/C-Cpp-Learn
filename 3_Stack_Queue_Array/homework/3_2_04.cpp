#include <cstddef>
#include <iostream>
using namespace std;

typedef struct LinkNode{
    int data;
    LinkNode * next;
}LinkNode;
typedef struct {
    LinkNode * front, *rear;
}*LinkQueue;
void InitQueue(LinkQueue &Q){
    Q->front = Q->rear = new LinkNode();
    Q->front->next = NULL;
}
bool isEmpty(LinkQueue Q){
    return Q->front == Q->rear;
}
bool EnQueue(LinkQueue &Q, int i){
    LinkNode *p;
    if(Q->rear->next == NULL)
        p = new LinkNode();
    else
        p = Q->rear->next;
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
    Q->rear->next = p;
    return true;
}
bool GetTop(LinkQueue Q, int &i){
    if(isEmpty(Q))
        return false;
    i = Q->front->data;
    return true;
}
int main(){
    LinkQueue Q;
    InitQueue(Q);
    EnQueue(Q, 10);
    EnQueue(Q, 20);
    return 0;
}