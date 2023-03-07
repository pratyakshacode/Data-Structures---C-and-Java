#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n){

    for(int i=1; i<n; i++){

        int temp = arr[i];
        int j=i-1;

        for(; j>=0; j--){
            if(arr[j]>temp){
                arr[j+1]= arr[j];
            }
            else break;
        }

        arr[j+1] = temp;
    }

        for(int i=0; i<n; i++) cout<<arr[i]<<" ";
        cout<<endl;
}

void insertionSortWhile(int arr[], int n){

    for(int i=1; i<n; i++){

        int temp = arr[i];
        int j = i-1;

        while(j>=0 && arr[j] > temp){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = temp;
    }

        for(int i=0; i<n; i++){
            cout<<arr[i]<<" ";
        }
    cout<<endl;
}

int main(){

    int arr[]={2,5,3,4,8};
    insertionSort(arr,5);
    insertionSortWhile(arr,5);

    return 0;
}