#include<bits/stdc++.h>
using namespace std;

//to find the element in the sorted array

int binarySearch(int arr[],int start, int n, int key){

    int s = start;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s<=e){
        
        if(key == arr[mid]) return mid;
        else if (key < arr[mid]) e = mid - 1;
        else s = mid+1;

        mid = s + (e-s)/2;
    }

    return -1;
}
//to find the pivot element and it will help to find where to go in the array

int findPivot(int arr[], int n){

    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2; 

    while(s<e){
    if(arr[mid]>=arr[0]) s = mid+1;
    else e = mid;
   
    mid = s + (e-s)/2;
    }

    return s;
}

// this funtion will decide the position of the array in which the element is present

int searchInRotatedArray(int arr[], int n, int key){

    int pivot = findPivot(arr,n);

    if(key >= arr[pivot] && key <= arr[n-1]){
        return binarySearch(arr,pivot,n,key);
    } 
    else return binarySearch(arr,0,pivot,key);

}
int main(){

    int rotatedArr[6] = {7,9,10,2,3,5};
    int pivot = findPivot(rotatedArr,6);
    
    cout<<searchInRotatedArray(rotatedArr,6,5);



    return 0;
}