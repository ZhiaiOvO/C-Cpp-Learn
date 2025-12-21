#include <cctype>
#include <cstdlib>
#include <iostream>
using namespace std;
#define MaxSize 50

typedef struct{
    int data[MaxSize];
    int top;
}SqStack;
void InitStack(SqStack &s){
    s.top =-1;
}
bool isEmpty(SqStack s){
    return s.top == -1;
}
bool Push(SqStack &s, int i){
    if(s.top == MaxSize - 1)
        return false;
    s.data[++s.top] = i;
    return true;
}
bool Pop(SqStack &s, int &i){
    if(s.top == -1)
        return false;
    i = s.data[s.top--];
    return true;
}
bool GetTop(SqStack s, int &i){
    if(s.top == -1)
        return false;
    i = s.data[s.top];
    return true;
}