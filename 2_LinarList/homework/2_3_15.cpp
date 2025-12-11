#include <iostream>
using namespace std;

typedef struct LNode{
    int  data;
    LNode * next;
}LNode, *LinkList;
void initList(LinkList &L){
    L = new LNode();
    L->next = NULL;
}
void createListTail(LinkList &L, int n, LNode *&r){
    LNode *s;
    r = L; // r is the tail pointer
    for(int i = 0; i < n; ++i){
        s = new LNode();
        cin >> s->data;
        r->next = s;
        r = s;
    }
    r->next = L->next->next->next->next->next->next; // terminate the list
}
int main(){
    LinkList L;
    LNode *r;
    int n;
    cin >> n;
    createListTail(L, n, r);
    LNode *q = L->next;
    for (int i = 0; i < n; i++)
    {
        if (q = r->next)
        {
            cout << q->data << endl;
            break;
        }
        q = q->next;
    }
}