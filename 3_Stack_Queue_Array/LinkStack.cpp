#include <cstddef>
#include <iostream>
using namespace std;

typedef struct LinkNode{
    int data;
    LinkNode * next;
}*LinkStack;
void InitStack(LinkStack &s){
    s->next = NULL;
}
bool isEmpty(LinkStack s){
    return s == NULL;
}
bool Push(LinkStack &s, int i){
    // if(s.top == MaxSize - 1)
    //     return false;
    LinkNode *p = new LinkNode();
    p->data = i;
    p->next = s;
    s = p;
    return true;
}
bool Pop(LinkStack &s, int &i){
    if(s == NULL)
        return false;
    i = s->data;
    s = s->next;
    return true;
}
bool GetTop(LinkStack s, int &i){
    if(s == NULL)
        return false;
    i = s->data;
    return true;
}