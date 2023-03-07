#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[5]={1,2,3,4,5};

    int temp = arr[0];
    for(int i=0;i<4;i++){
        arr[i]= arr[i+1];
    }
    cout<<temp<<endl;
    arr[4]= temp;

    for(int i =0;i<5;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}