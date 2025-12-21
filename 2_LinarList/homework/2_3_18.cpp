#include <iostream>
using namespace std;

typedef struct LNode{
    char data;
    LNode * next;
}LNode, *LinkList;
void initList(LinkList &L){
    L = new LNode();
    L->next = NULL;
}
void createListTail(LinkList &L, char str[]){
    LNode *p, *r = L;
    for (int i = 0; str[i] != '\0'; i++){
        p = new LNode;
        p->data = str[i];
        p->next = r->next;
        r->next = p;
        r = p;
    }
}
int main(){
    LinkList L1, L2;
    initList(L1);
    initList(L2);
    createListTail(L1, (char[]){'l', 'o', 'a', 'd', 'i', 'n', 'g', '\0'});
    createListTail(L2, (char[]){'b', 'e', 'i', 'n', 'g', '\0'});
    int n1 = 0, n2 = 0;
    LNode *p1 = L1->next;
    LNode *p2 = L2->next;
    while (p1 != NULL)
    {
        n1++;
        p1 = p1->next;
    }
    while (p2 != NULL)
    {
        n2++;
        p2 = p2->next;
    }
    if(n1 < n2){
        LinkList temp = L1;
        int tempn = n1;
        n1 = n2;
        n2 = tempn;
        L1 = L2;
        L2 = temp;
    }
    p1 = L1->next;
    p2 = L2->next;
    for (int i = 0; i < n1-n2; i++){
        p1 = p1->next;
    }
    LNode *res = NULL;
    while (p1 != NULL && p2 != NULL){
        if(p1->data == p2->data){
            res = p1;
            while (res != NULL){
                cout << res->data;
                res = res->next;
            }
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    return 0;
}