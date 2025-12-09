#include <cstddef>
#include <cstdlib>
#include <iostream>
using namespace std;

typedef struct LNode{
    int data;
    LNode * next;
}LinkList;

void DelElem(LinkList *L, int e){
    if (L->next == NULL) {
        return;
    }
    LNode * p = L->next;
    if (p->data == e) {
        L->next = p->next;
        free(p);
        DelElem(L, e);
    }else{
        DelElem(p, e);
    }
}
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
int main(){
    LinkList *L;
    test(L);
    DelElem(L, 5);
    LNode *p = L->next;
    while(p != NULL){
        cout<<p->next<<endl;
        p = p->next;
    }

}