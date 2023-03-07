#include<bits/stdc++.h>
using namespace std;


void unique(int arr[],int n){
    int arr2[n]={0};

    for(int i=0; i<n; i++){
        arr2[arr[i]]+=1;
    }

    for(int i=0; i<n; i++){
        if(arr2[i]==1)
        cout<<i;
    }

}
int main(){
    int arr[10] = {1,1,2,2,3,4,4,6};
    unique(arr,8);
    return 0;
}