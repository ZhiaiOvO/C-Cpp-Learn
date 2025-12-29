#include <iostream>
using namespace std;

int main(){
    int A[]={50, 26, 38, 80, 70, 90, 8, 30, 40, 20};
    int n = 10;
    int i, j, temp;
    for(i=1;i<n;i++){
        if(A[i]<A[i-1]){
            temp=A[i];
            for(j=i-1;j>=0&&A[j]>temp;j--){
                A[j+1]=A[j];
            }
            A[j+1]=temp;
        }
    }
    for(int i = 0; i<n;i++){
        cout<<A[i]<<endl;
    }
    return 0;
}