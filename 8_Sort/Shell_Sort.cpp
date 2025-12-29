#include <iostream>
using namespace std;

int main(){
    int n = 10;
    int A[]={10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int i, j, k, dk, temp;
    for(dk = n/2; dk>=1; dk/=2){
        for(i = 0; i<dk; i++){
            for(j = i + dk; j<n; j+=dk){
                if(A[j-dk]>A[j]){
                    temp=A[j];
                    for(k = j-dk; k>=0&&temp<A[k]; k-=dk)
                        A[k+dk] = A[k];
                    A[k+dk] = temp;
                }
            }
        }
    }
    for(int i = 0; i<n;i++){
        cout<<A[i]<<endl;
    }
    return 0;
}