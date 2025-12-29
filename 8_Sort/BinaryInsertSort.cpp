#include <iostream>
using namespace std;

int main(){
    int n = 10;
    int A[]={10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int i, j, temp, low, high, mid;
    for(i=1;i<n;i++){
        if(A[i]<A[i-1]){
            temp=A[i];
            low=0,high=i-1;
            while(low<=high){
                mid=(low+high)/2;
                if(A[mid]>temp)
                    high=mid-1;
                else
                    low=mid+1;
            }
            for(j=i-1;j>=low;j--){
                A[j+1]=A[j];
            }
            A[low]=temp;
        }
    }
    for(int i = 0; i<n;i++){
        cout<<A[i]<<endl;
    }
    return 0;
}