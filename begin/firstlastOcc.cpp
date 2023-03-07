#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int key){
    int s = 0;
    int e = n-1;
    int mid = 0;
    
    while(s<=e){
        int mid = s+(e-s)/2;

        if(key == arr[mid]) return mid;
        else if(key<arr[mid]) e = mid - 1;
        else s = s+1;
    }
    return -1;
}

int firstOcc(int arr[], int n, int key){

    int s = 0;
    int e = n-1;
    int ans = -1;
    int mid = s + (e-s)/2;

    while(s<=e){

        if(key == arr[mid]){
            ans = mid;
            e = mid - 1;
        }
        else if(key < arr[mid]) e = mid-1;
        else s = mid + 1;

        mid = s + (e-s)/2;
    }
    cout<<endl;
    return ans;
}

int lastOcc(int arr[], int n, int key){

    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;

    while(s<=e){

        if(key == arr[mid]){
            ans = mid;
            s = mid + 1; 
        }
        else if(key < arr[mid]) e = e-1;
        else s = s+1;
        mid = s + (e-s)/2;

    }
    cout<<endl;
    return ans ;
}
int main(){

    int arr[6]={1,2,3,4,5,6};
    int arr2[6]= {1,2,2,3,3,3};
    // int a = binarySearch(arr,6,4);
    // cout<<a;

    cout<<firstOcc(arr2,6,2);
    cout<<lastOcc(arr2,6,2);

    

    return 0;
}