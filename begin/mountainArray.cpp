#include<bits/stdc++.h>
using namespace std;

int findPeak(int arr[], int n){

    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s<e){

        if(arr[mid]<arr[mid+1]) s = mid + 1;
        else e = mid;

        mid = s + (e-s)/2;
    }

    return s;
}
int main(){
    int mntnArr[8]={5,6,7,8,9,10,2,1};
    cout<<findPeak(mntnArr,8);

    return 0;
}