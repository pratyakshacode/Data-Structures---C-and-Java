#include<bits/stdc++.h>
using namespace std;

void print(int arr[], int n){
    int i=0;
    while(i<n){
        cout<<arr[i]<<" ";
        i++;
    }
}


void rotateArray(int arr[], int temp[], int n, int k){

    for(int i=0; i<n; i++){

        temp[(i+k)%n] = arr[i];
    }
}

int main(){

    int arr[] = {2,3,4,5,6,7,8};
    int res[7] = {0};

    int k;

    cout<<"Enter how many digits you want to rotate: "<<endl;
    cin>>k;

    rotateArray(arr,res,7,k);
    print(res,7);
    return 0;
}