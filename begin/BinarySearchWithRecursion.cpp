#include<bits/stdc++.h>
using namespace std;

//checking whether the array is sorted or not

bool Sorted(int arr[], int n){

    if(n == 0 || n == 1) return true;

    if(arr[0] > arr[1]) return false;
    else return Sorted(arr+1,n-1);

}

int sumOfArray(int arr[], int n){
   
    int sum = 0;

    if(n == 0) return 0;
    if(n == 1) return arr[0];
    else{
        sum = arr[0] + sumOfArray(arr+1,n-1);
    
    }
return sum;

}

bool linearSearch(int arr[], int n, int key){

    if(n == 0) return false;
    if(arr[0] == key)return true;

    else{
        return linearSearch(arr+1,n-1,key);
    
    }
}

int binarySeachUsingRecursion(int arr[], int s, int e, int key){

    if(s > e) return -1;
    
    int mid = s + (e-s)/2;

    if(arr[mid] == key) return mid;

    if(arr[mid] < key) return binarySeachUsingRecursion(arr,mid+1,e,key);
    else return binarySeachUsingRecursion(arr,s,mid-1,key);


}

int main(){
    int n=5;
    int arr[] = {1,2,3,5,6};
    
    cout << Sorted(arr, n) << endl;
    cout << sumOfArray(arr,n) << endl;
    cout << linearSearch(arr,n,3) << endl;
    cout << binarySeachUsingRecursion(arr,0,n-1,1);

    return 0;
}