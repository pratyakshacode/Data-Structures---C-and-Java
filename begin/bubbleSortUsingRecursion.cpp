#include<bits/stdc++.h>
using namespace std;

void print(int arr[], int n){
    for(int i=0; i<n; i++) cout <<arr[i] <<" ";
    cout <<endl;
}
void bubbleSort(int* arr, int n){
    

    if(n == 0 || n == 1) return;

    for(int i=0; i<n-1; i++){
        if(arr[i] > arr[i+1]) swap(arr[i],arr[i+1]);
    }

    bubbleSort(arr, n-1);
}

void selectionSort(int* arr, int n){
    
    print(arr,n);
    //basecase
    if(n == 0 || n == 1) return;

    int index = -1;
    int mini = 0;

    for(int j=0; j<n; j++){
       
        mini = arr[j];

        if(arr[j] < mini){
            mini = arr[j];
            index = j;
        }
    }

    swap(arr[0],arr[index]);
    selectionSort(arr+1,n-1);

}

int main(){

    int arr[5]={10,11,9,5,6};
    selectionSort(arr,5);

    for(int i=0; i<5; i++) cout << arr[i] << " ";

    return 0;
}