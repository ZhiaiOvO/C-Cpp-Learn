#include <iostream>
using namespace std;

typedef struct LNode{
    int  data;
    LNode * next;
}LNode, *LinkList;
void initList(LinkList &L){
    L = NULL;
}
void createListTail(LinkList &L, int n){
    for (int i = n; i > 0; i--){
        LNode *p = new LNode;
        p->data = i;
        p->next = L;
        L = p;
    }
    
}
int main(){
    LinkList L;
    initList(L);
    int n, k;
    cin >> n >> k;
    createListTail(L, n);
    int len = 0;
    LNode *p = L;
    int an[100002];
    int i = 0;
    while(p != NULL){
        len++;
        an[i++] = p->data;
        p = p->next;
    }
    printf("%d\n", an[len-k]);
    return 0;
}