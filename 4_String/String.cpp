#include <asm-generic/errno-base.h>
#include <cstdlib>
#include <iostream>
#include <iterator>
using namespace std;
#define MAXLEN 255

typedef struct {
    char *ch;
    int length;
}HeapString;

void InitString(HeapString &s){
    s.ch = new char(sizeof(char) * MAXLEN);
    s.length = 0;
}
void StrAssign(HeapString &s, HeapString chars){
    for(int i = 0; i < chars.length; i++){
        s.ch[i] = chars.ch[i];
    }
    s.length = chars.length;
}
void StrCopy(HeapString &s, HeapString t){
    s.ch = t.ch;
    s.length = t.length;
}
bool IsEmpty(HeapString s){
    return s.length <= 0;
}
int StrCompare(HeapString s, HeapString t){
    int i = 0;
    while(s.ch[i] != '\0' && t.ch[i] != '\0'){
        if(s.ch[i] != t.ch[i]){
            return s.ch[i] - t.ch[i];
        }
        i++;
    }
    return s.length - t.length;
}
int StrLength(HeapString s){
    return s.length;
}
void Concat(HeapString &T, HeapString S1, HeapString S2){
    T.ch = new char;
    int l1 = S1.length, l2 = S2.length;
    for(int i = 0; i < l1; i++){
        T.ch[i] = S1.ch[i];
    }
    for(int i = l1; i < l1 + l2; i++){
        T.ch[i] = S2.ch[i-l1];
    }
    T.length = l1 + l2;
}
bool SubString(HeapString &Sub, HeapString S, int pos, int len){
    if(pos + len > S.length){
        return false;
    }
    for(int i = 0; i < len; i++){
        Sub.ch[i] = S.ch[i + pos - 1];
    }
    Sub.length = len;
    return true;
}
int Index(HeapString S, HeapString T){
    int i = 0, j = 0;
    while(i < S.length && j < T.length){
        if(S.ch[i] == T.ch[j]){
            i++;
            j++;
        }else{
            i = i - j + 1;
            j = 0;
        }
    }
    if(j > T.length)
        return i - T.length;
    else
        return -1;
}
void ClearString(HeapString &s){
    s.length = 0;
}
void DestoryString(HeapString &s){
    delete s.ch;
    delete &s;
}

int main(){
    HeapString s, chars;
    InitString(s);
    InitString(chars);
    char c[5] = {'1', '2', '3', '4', '5'};
    chars.ch = c;
    chars.length = 5;
    StrAssign(s, chars);

    for(int i = 0; i < s.length; i++){
        cout<<s.ch[i]<<endl;
    }
    return 0;
}