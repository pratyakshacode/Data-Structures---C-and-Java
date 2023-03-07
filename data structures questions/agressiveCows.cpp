/* In this problem we will have the number of cows and an array which will represent the distance between the cows and we have to place the cows into the stoll in such a way that they will not hit and harm each other 
There are some following conditions : -
1. all the cows should be placed in the stoll
2. the maximum distance between the cows should be minimum
*/

#include<bits/stdc++.h>
using namespace std;


bool isPossible(int arr[], int m, int n, int mid){

    int lastPos = arr[0];
    int cowCount = 1;

    for(int i=0; i<n; i++){
        if(arr[i]-lastPos >= mid){
            cowCount++;

            if(cowCount == m){
                return true;
            }

            lastPos = arr[i];
        }
    }

    return false;
}


int aggresiveCows(int arr[], int m, int n){

    sort(arr,arr+n);
    int s = 0;
    int maxi = -1;

    for(int i=0; i<n; i++){
        maxi = max(maxi,arr[i]);
    }
    int ans = -1;
    int e = maxi ;
    int mid = s + (e-s)/2;

    while(s<=e){

        if(isPossible(arr,m,n,mid)){
            ans = mid;
            s = mid + 1;
        }
        else e = mid - 1;
        
        mid = s + (e-s)/2;
    }
return ans ;
}

int main(){

    int arr[] = {4,2,1,3,6};
    cout<<aggresiveCows(arr,2,5);
    
    return 0;
}