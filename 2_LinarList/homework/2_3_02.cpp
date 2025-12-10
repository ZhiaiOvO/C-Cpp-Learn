#include <cstddef>
#include <iostream>
#include <cmath>
using namespace std;

typedef struct LNode{
    int data;
    LNode * next;
}*LinkList;

void initList(LinkList &L){
    L = new LNode();
    L->next = NULL;
}
void DelMin(LinkList &L){
    int min = -1;
    LNode * p = L->next;
    LNode * minNode = NULL;
    while(p != NULL){
        if(p->data <= min){
            minNode = p;
            min = p->data;
            continue;
        }
        p = p->next;
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
void test(LinkList &L){
    int i = 0;
    LNode *p;
    while(i<=10){
        p = new LNode();
        p->data = ++i;
        p->next = L->next;
        L->next = p;
    }
}
int main(){
    LinkList L;
    initList(L);
    test(L);
    LNode * p = L->next;
    while(p != NULL){
        cout<<p->data<<endl;
        p = p->next;
    }
    DelMin(L);
    cout<<endl<<endl;
    while(p != NULL){
        cout<<p->data<<endl;
        p = p->next;
    }
}