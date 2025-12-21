#include <cstddef>
#include <cstdio>
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
void Search_k_1(LinkList &L, int k){
    int len = 0;
    LNode *p = L;
    int an[100002];// 10分/15分
    int i = 0;
    while(p != NULL){
        len++;
        an[i++] = p->data;
        p = p->next;
    }
    printf("%d\n", an[len-k]);
}
void Search_k_2(LinkList &L, int k){
    LNode *p = L, *q = L;
    int count = 0;
    while(p != NULL){
        if(count < k) count++;
        else q = q->next;
        p = p->next;
    }
    if(count < k){
        printf("%d\n",-1);
    }else{
        cout<<q<<" "<<q->data;
    }
}
int main(){
    LinkList L;
    initList(L);//without head node
    int n, k;
    cin >> n >> k;
    createListTail(L, n);
    Search_k_1(L, k);
    cout<<endl<<endl;
    Search_k_2(L, k);
    return 0;
}