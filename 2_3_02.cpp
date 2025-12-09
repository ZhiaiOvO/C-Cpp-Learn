#include <iostream>
using namespace std;

typedef struct LNode{
    int data;
    LNode * next;
}LinkList;

void initList(LinkList *L){
    LNode * head;
    L = head;
    head->next = NULL;
}
void test(LinkList *L){
    int i = 0;
    LNode *p = L->next;
    while(i<=10){
        p->data = ++i;
        p = p->next;
    }
}
void DelMin(LinkList *L){
    int min = -(2^31);
    LNode * p = L->next;
    LNode * minNode = NULL;
    while(p != NULL){
        if(p->data <= min){
            minNode = p;
            min = p->data;
        }
    }
    if(minNode != NULL){
        LNode * r = minNode->next;
        if(r == NULL){
            free(minNode);
        }
        minNode->next = r->next;
        minNode->data = r->data;
        free(r);
    }
}