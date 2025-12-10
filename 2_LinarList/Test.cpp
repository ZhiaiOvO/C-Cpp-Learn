#define InitSize 10
#include <iostream>
using namespace std;
struct Test
    {
        /* data */
        int id;
        int age;
    };
typedef struct {
    int * data;
    int MaxSize;
    int length;
}SqList;
void increaseSize(SqList &L, int len);
void initList(SqList &L){
    L.data = new int[InitSize];
    for (int i = 0; i < InitSize; i++)
    {
        L.data[i] = 0;
    }
    
    L.length = 0;
    L.MaxSize = InitSize;
}
bool insertList(SqList &L, int i, int e){
    if(i<0 || i>L.length){
        cout<<"insert position error!"<<endl;
        return false;
    }
    if (i >= L.MaxSize)
    {
        increaseSize(L, i - L.MaxSize + 1);
        return false;
    }
    
    for (int j = L.length; j > i; j--)
    {
        L.data[j] = L.data[j - 1];
    }
    L.data[i] = e;
    L.length++;
    return true;
}
bool deleteList(SqList &L, int i){
    if (i < 0 || i >= L.length){
        cout<<"delete position error!"<<endl;
        return false;
    }
    for (int j = i; j < L.length; j++){
        L.data[j] = L.data[j + 1];
    }
    L.data[L.length - 1] = 0;
    L.length--;
    return true;
}
void increaseSize(SqList &L, int len){
    int * p = L.data;
    L.data = new int[L.MaxSize + len];
    for (int i = 0; i < L.length; i++)
    {
        L.data[i] = p[i];
    }
    L.MaxSize += len;
    delete [] p;
}
int getElement(SqList L, int i){
    return *(L.data + i);//same as: return L.data[i]; 
}
void setElement(SqList &L, int i, int e){
    if(i<0 || i>=L.MaxSize){
        cout<<"set position error!"<<endl;
        return;
    }
    L.data[i] = e;
    L.length++;
}

int main(){
    SqList L;
    initList(L);
    for (int i = 0; i < InitSize; i++)
    {
        setElement(L, i, i + 1);
    }
    insertList(L, 5, 100);
    deleteList(L, 2);
    for (int i = 0; i < L.length; i++)
    {
        cout<<getElement(L, i)<<" ";
    }
    cout << endl;
    return 0;
}