#include <cstddef>
#include <iostream>
using namespace std;

typedef struct LNode{
    int  data;
    LNode * next;
}LNode, *LinkList;
void initList(LinkList &L){
    L = new LNode();
    L->next = NULL;
}
void test(LinkList &L){
    int i=1;
    while (i<=10) {
        LNode * p = new LNode;
        p->data = i++;
        p->next = L->next;
        L->next = p;
    }
}
void Reserve(LinkList &L){
    LNode *p = L->next;
    LNode *q = L->next;
    LNode *r;
    while(p != NULL){
        r = p->next;
        p->next = L->next;
        L->next = p;
        p = r;
    }
    q->next = NULL;
}
int main(){
    LinkList L;
    initList(L);
    test(L);
    LNode *i = L->next;
    while(i != NULL){
        cout<<i->data<<endl;
        i = i->next;
    }
    cout<<endl<<endl<<endl;
    Reserve(L);
    i = L->next;
    while (i!= NULL) {
        cout<<i->data<<endl;
        i = i->next;
    }
}