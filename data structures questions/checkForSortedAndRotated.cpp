#include<bits/stdc++.h>
using namespace std;

bool check(int arr[], int n){

    int count = 0;

    for(int i=1; i<n; i++){
        if(arr[i-1]>arr[i]) count++;
    }

    if(arr[n-1]>arr[0]) count++;

    return count <= 1;

}
int main(){

    int arr[7]={7,8,9,1,2,3,4};   //sorted and rotated array
    int arr2[5]={1,2,3,4,5};      // only sorted array
    int arr3[5] = {5,6,7,2,8};    //neither sorted nor rotated


    cout<<check(arr,7);
    cout<<check(arr2,5);
    cout<<check(arr3,5);

    return 0;
}