#include<bits/stdc++.h>
using namespace std;

int partition(int* arr, int s, int e){

    int pivot = arr[s];
    int cnt = 0;

    for(int i=s+1; i <= e; i++){

        if(arr[i] < pivot) cnt++;
    }
    
    int pivotIndex = s + cnt;

    swap(arr[pivotIndex], arr[s]);

    int i = s;
    int j = e;

    while(i < pivotIndex && j > pivotIndex){

        while(arr[i] <= pivot){
            i++;
        }

        while(arr[j] > pivot){
            j--;
        }

        if(arr[i] > pivot && arr[j] < pivot) swap(arr[i++], arr[j--]);
    }

return pivotIndex;
}
void quickSort(int* arr, int s, int e){

    //base case
    if(s >= e) return;

    // int mid = s + (e-s)/2;

    int p = partition(arr, s, e);

    quickSort(arr, s, p-1);
    quickSort(arr, p + 1, e);
    
}

int main(){

    int n = 6;
    int arr[n] = {1,2,1,2,1,2};

    quickSort(arr, 0, n-1);
    for(auto value : arr) cout << value << " ";
    return 0;
}