#include <cstddef>
#include <cstdlib>
#include <iostream>
using namespace std;

typedef struct LNode{
    int  data;
    LNode * next;
}LNode, *LinkList;

void DelElem(LinkList &L, int e){
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
void initList(LinkList &L){
    L = new LNode();
    L->next = NULL;
}
void test(LinkList &L){
    int i = 10;
    LNode *p;
    while(i>0){
        p = new LNode();
        p->data = i--;
        p->next = L->next;
        L->next = p;
    }
}
int main(){
    LinkList L;
    initList(L);
    test(L);
    DelElem(L, 5);
    LNode *p = L->next;
    while(p != NULL){
        cout<<p->data<<endl;
        p = p->next;
    }

}