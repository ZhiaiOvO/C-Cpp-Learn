#include <cstddef>
#include <cstdio>
#include <iostream>
#include <type_traits>
using namespace std;

typedef struct LNode{
    int  data;
    LNode * next;
}LNode, *LinkList;
void initList(LinkList &L){
    L = NULL;
}
LinkList test(LinkList &L, int n){//此题没有头节点
    int i=1;
    // L = new LNode;
    // L->next = NULL;
    while (i<=n) {
        LNode *p = new LNode;
        p->data = i++;
        p->next = L;
        L = p;
    }
    return L;
}
void MoveRight(LinkList &L, int n, int k){
    int j = n-k;
    LNode *q = L;
    while(q->next != NULL){
        q = q->next;
    }
    while(j > 0){
        q->next = L;
        L = L->next;
        q = q->next;
        q->next = NULL;
        j--;
    }
}
int main(){
    LinkList L;
    initList(L);
    int n, k;
    cin>>n>>k;
    L = test(L, n);
    LNode *i = L;
    while(i != NULL){
        cout<<i->data<<endl;
        i = i->next;
    }
    cout<<endl<<endl<<endl;
    MoveRight(L, n, k);
    i = L->next;
    while (i!= NULL) {
        cout<<i->data<<endl;
        i = i->next;
    }
}