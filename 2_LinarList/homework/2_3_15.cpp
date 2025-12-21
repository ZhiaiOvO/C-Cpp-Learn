#include <cstddef>
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
void createListTail(LinkList &L, int n){
    LNode *s;
    LNode * r = L; // r is the tail pointer
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
    int n;
    cin >> n;
    createListTail(L, n);
    LNode *fast = L->next, *slow = L->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow) break;
    }
    cout<<endl<<endl;
    if(fast == NULL){
        cout<<"-1";
    }else {
        LNode * p1 = L->next, * p2 = slow;
        while(p1 != p2){
            p1 = p1->next;
            p2 = p2->next;
        }
        cout<<p1<<" "<<p1->data;
    }
    return 0;
}