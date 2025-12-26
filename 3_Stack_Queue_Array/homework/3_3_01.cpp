#include <cstddef>
#include <iostream>
#include <string>
using namespace std;

typedef struct LinkNode{
    char data;
    LinkNode * next;
}LinkNode;
typedef struct{
    LinkNode *top;
}*LinkStack;
void InitStack(LinkStack &s){
    s->top = NULL;
}
bool isEmpty(LinkStack s){
    return s->top == NULL;
}
bool Push(LinkStack &s, char i){
    LinkNode *p = new LinkNode();
    p->data = i;
    p->next = s->top;
    s->top = p;
    return true;
}
bool Pop(LinkStack &s, char &i){
    if(isEmpty(s))
        return false;
    LinkNode *p = s->top;
    i = p->data;
    s->top = p->next;
    delete p;
    return true;
}
bool GetTop(LinkStack s, char &i){
    if(isEmpty(s))
        return false;
    i = s->top->data;
    return true;
}

int main(){
    LinkStack stack;
    InitStack(stack);
    char ch[] = "({()((()))()})";
    for(int i = 0; ch[i] != '\0'; i++){
        char top;
        switch(ch[i]){
            case '(':
            case '[':
            case '{':
                Push(stack, ch[i]);
                break;
            case ')':
                top = Pop(stack, top) ? top : '\0';
                if(top != '('){
                    cout << "Unmatched ) at position " << i << endl;
                    return 0;
                }
                break;
            case ']':
                top = Pop(stack, top) ? top : '\0';
                if(top != '['){
                    cout << "Unmatched ] at position " << i << endl;
                    return 0;
                }
                break;
            case '}':
                top = Pop(stack, top) ? top : '\0';
                if(top != '{'){
                    cout << "Unmatched } at position " << i << endl;
                    return 0;
                }
                break;
            default:
                cout << "Invalid character " << ch[i] << " at position " << i << endl;
                return 0;
                break;
        }
    }
    string ss;
    cout<< "All parentheses are matched." << endl;
    return 0;
}