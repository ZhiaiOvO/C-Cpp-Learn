#include <cstddef>
#include <iostream>
using namespace std;

typedef struct LinkNode{
    int data;
    LinkNode * next;
}*LinkStack;
void InitStack(LinkStack &s){
    s = NULL;
}
bool isEmpty(LinkStack s){
    return s == NULL;
}
bool Push(LinkStack &s, int i){
    // if(s.top == MaxSize - 1)
    //     return false;
    LinkNode *p = new LinkNode();
    p->data = i;
    p->next = s;
    s = p;
    return true;
}
bool Pop(LinkStack &s, int &i){
    if(s == NULL)
        return false;
    i = s->data;
    s = s->next;
    return true;
}
bool GetTop(LinkStack s, int &i){
    if(s == NULL)
        return false;
    i = s->data;
    return true;
}
typedef struct LNode{
    int data;
    LNode * next;
}LNode, *LinkList;
void initList(LinkList &L){
    L = new LNode();
    L->next = NULL;
}
void test(LinkList &L){
    char in;
    cin>>in;
    while(in != '.'){
        L->data =(int) in;
        LNode *p = new LNode;
        p->next = L;
        L = p;
        cin>>in;
    }
}
int main(){
    LinkList L;
    LinkStack S;
    initList(L);
    InitStack(S);
    test(L);
    LNode *p = L->next;
    while(p != NULL){
        Push(S, p->data);
        p = p->next;
    }
    p = L->next;
    while(p != NULL){
        int x;
        if(!Pop(S, x)){
            cout<<"false";
            return 0;
        }
        if(x != p->data){
            cout<<"false";
            return 0;
        }
        p = p->next;
    }
    cout<<"true";
    return 0;
}