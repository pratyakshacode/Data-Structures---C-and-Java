#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n){
    bool swapItem = false;

    for(int i=1; i<n; i++){

        for(int j=0; j<n-i; j++){
            if(arr[j+1]<arr[j]){
                swap(arr[j],arr[j+1]);
                swapItem = true;
            }
        }

        if(swapItem == false) {
        cout<<"Your array was already sorted"<<endl;
                break;
        }
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
}


int main(){

        int arr[]={3,5,2,1,8};
        int sortedArray[]={1,2,3,4,5,6};
        bubbleSort(arr,5);
        bubbleSort(sortedArray,6);

    return 0;
}