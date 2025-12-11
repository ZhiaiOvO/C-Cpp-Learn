#include <cstddef>
#include <iostream>
#include <iterator>
using namespace std;

typedef struct LNode{
    int  data;
    LNode * next;
}LNode, *LinkList;
void initList(LinkList &L){
    L = new LNode();
    L->next = NULL;
}
void createList(LinkList &L, int &n){
    LNode *p, *r = L;
    int in;
    cin>>in;
    while(in != -1){
        if (in>=n) {
            n = in;
        }
        p = new LNode;
        p->data = in;
        p->next = r->next;
        r->next = p;
        r = p;
        cin>>in;
    }
}
int main(){
    LinkList L;
    initList(L);
    int n=-1;
    createList(L, n);
    int an[n+1];
    for(int i = 0; i < n+1; i++){
        an[i] = 0;
    }
    LNode *p = L->next;
    LNode *r;
    while(p != NULL){
        if(an[p->data] != 0){
            r = p->next;
            if(r == NULL){
                delete p;
                break;
            }
            p->next = r->next;
            p->data = r->data;
            delete r;
            continue;
        }
        an[p->data]++;
        p = p->next;
    }
    p = L->next;
    while(p != NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
}