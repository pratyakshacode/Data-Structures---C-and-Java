#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int s, int e){

    int pivot = arr[s];
    int count = 0;

    //finding the no of elements less than the pivot 
    for(int i=s+1; i<=e; i++){
        if(arr[i] < pivot) count++;
    }

    int pivotIndex = s + count; //the index for the pivot
    swap(arr[pivotIndex],arr[s]); //putting the pivot on the right place 

    //checking for the elements on the left (should be less than pivot) and right( should be greater than pivot)
    // or sorting the left and right parts by two pointers

    int i=s, j=e;

    while(i < pivotIndex && j > pivotIndex){
        
        while(arr[i] <= pivot){
            i++;
        }

        while(arr[j] > pivot){
            j--;
        }

        swap(arr[i++],arr[j--]);
    } 

    return pivotIndex;

}

void quickSort(int arr[], int s, int e){

    //base case
    if(s >= e) return;

    //finding the right index for each element
    int p = partition(arr,s,e);

    // for sorting the left part
    quickSort(arr,s,p-1);   

    //for sorting the right part
    quickSort(arr,p+1,e);

}

int main(){

    int arr[14] = {10,20,50,1,2,3,5,6,4,1,1,1,1};
    int n = 14;

    quickSort(arr,0,n-1);

    for(int i=0; i<n; i++) cout << arr[i] << " ";

    return 0;
}