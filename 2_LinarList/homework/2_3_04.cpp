#include <cstddef>
#include <iostream>
#include <type_traits>
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
bool DelElem(LNode *p, LNode *pr){
    pr->next = p->next;
    p->next = NULL;
    delete p;
    return true;
}
bool DelElems(LinkList &L, int a, int b){
    if (a>b||L->next == NULL) {
        return false;
    }
    LNode *p = L->next,*pr = L;
    while(p != NULL){
        if (p->data >= a && p->data <= b) {
            DelElem(p, pr);
            p = pr->next;
            continue;
        }
        pr = p;
        p = pr->next;
    }
    return true;
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
    DelElems(L, 3, 7);
    i = L->next;
    while (i!= NULL) {
        cout<<i->data<<endl;
        i = i->next;
    }
}