#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n){

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
}
void selectionSortUnstable(int arr[], int n){

    for(int i=0; i<n-1; i++){
        
        int minPos = i;

        for(int j=i+1; j<n; j++){
            if(arr[minPos] > arr[j]) minPos = j;
        }

        swap(arr[i], arr[minPos]);
    }
    printArray(arr,n);
}


void selectionSortStable(int arr[], int n){

    for(int i=0; i<n-1; i++){

        int minPos = i;

        for(int j=i+1; j<n; j++){
            if(arr[minPos] > arr[j]) minPos = j;
        }

        int key = arr[minPos];

        while(minPos > i){
            arr[minPos] = arr[minPos-1];
            minPos--;
        }

        arr[i] = key;
    }

    printArray(arr,n);
}


int main(){

int arr[]= {2,4,1,3,8,9,6,2};
// selectionSortUnstable(arr,8);
selectionSortStable(arr,8);

    return 0;
}