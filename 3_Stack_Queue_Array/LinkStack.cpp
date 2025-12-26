#include <cstddef>
#include <iostream>
using namespace std;

typedef struct LinkNode{
    int data;
    LinkNode * next;
}LinkNode;
typedef struct{
    LinkNode *top;
}*LinkStack;
void InitStack(LinkStack &s){
    s->top = NULL;
}
bool isEmpty(LinkStack s){
    return s->top == NULL;
}
bool Push(LinkStack &s, int i){
    LinkNode *p = new LinkNode();
    p->data = i;
    p->next = s->top;
    s->top = p;
    return true;
}
bool Pop(LinkStack &s, int &i){
    if(isEmpty(s))
        return false;
    LinkNode *p = s->top;
    i = p->data;
    s->top = p->next;
    delete p;
    return true;
}
bool GetTop(LinkStack s, int &i){
    if(isEmpty(s))
        return false;
    i = s->top->data;
    return true;
}