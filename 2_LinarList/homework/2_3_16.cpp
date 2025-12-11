#include <iostream>
using namespace std;

typedef struct LNode{
    int  data;
    LNode * next;
}LNode, *LinkList;
typedef struct{
    int elem[100];
    int length;
}SqList;

void initList(LinkList &L){
    L = new LNode();
    L->next = NULL;
}
void initSqList(SqList *&S){
    S = new SqList;
    S->length = 0;
}
void createListTail(LinkList &L, int n){
    while (n>0) {
        LNode *p = new LNode;
        p->data = n*n;
        n--;
        p->next = L;
        L = p;
    }
}
void addElement(SqList *&S, int e){
    S->elem[S->length++] = e;
}
int main(){
    LinkList L;
    int n;
    cin >> n;
    createListTail(L, n);
    SqList *S;
    initSqList(S);
    LNode *p = L;
    for(int i = 0; i < n; i++){
        addElement(S, p->data);
        p = p->next;
    }
    int max = 0;
    for (int i = 0; i < n/2; i++)
    {
        if(S->elem[i] + S->elem[n-i-1] > max){
            max = S->elem[i] + S->elem[n-i-1];
        }
    }
    cout<<max;
}
