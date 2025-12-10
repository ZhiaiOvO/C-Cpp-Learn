
#include <iostream>
using namespace std;

typedef struct LNode{
    int  data;
    LNode * prev;
    LNode * next;
}LNode, *LinkList;
void initList(LinkList &L){
    L = new LNode();
    L->prev = NULL;
    L->next = NULL;
}