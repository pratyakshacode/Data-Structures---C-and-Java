#include<bits/stdc++.h>
using namespace std;

void print(int arr[], int n){

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}


void move(int arr[], int n){

    int initial = 0;
    int check = 0;

    while(check < n){
        
        if(arr[check] != 0){
            swap(arr[check],arr[initial]);
            initial ++;
        }
            check++;
    }
}
int main(){

    int arr[6] = {2,1,0,3,4,0};
    
    move(arr,6);
    print(arr,6);
  
    return 0;
}