#include <iostream>
using namespace std;

typedef struct LNode{
    int  data;
    LNode * next;
}LNode, *LinkList;
void initList(LinkList &L){
    L = new LNode();
    L->next = L;
}