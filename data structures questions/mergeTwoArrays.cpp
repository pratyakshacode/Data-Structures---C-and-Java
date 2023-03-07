#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n){

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}


void merge(int arr1[], int n, int arr2[], int m, int arr3[]){

    int i=0;
    int j=0;
    int k=0;

    while(i<n && j<m){
        
        if(arr1[i] <= arr2[j]){
            arr3[k++] = arr1[i++];
        }
        else if(arr2[j] < arr1[i]){
            arr3[k++] = arr2[j++];
        }
    }

    while(i < n){

        arr3[k++] = arr1[i++];
    }

    while(j < m){
        arr3[k++] = arr2[j++];
    }
}


int main(){

    int arr1[5]={1,3,5,7,9};
    int arr2[4]={1,5,7,9};
    int arr3[9]={0};

    merge(arr1,5,arr2,4,arr3);
    printArray(arr3,9);
    return 0;
}