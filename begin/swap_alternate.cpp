#include<bits/stdc++.h>
using namespace std;


void swapAlternate(int arr[], int n){

    for(int i=1; i<n; i+=2){
        int temp = arr[i];
        arr[i] = arr[i-1];
        arr[i-1] = temp;
    }

    cout<<"The array after reverse: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void swapAlternateShort(int arr[],int n){

    for(int i=1; i<n; i+=2)
    {
        swap(arr[i],arr[i-1]);
    }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" "; 
    }  
    cout<<endl; 
}
int main(){

    int arr[6] = {1,2,3,4,5,6};
    int brr[5]={1,2,3,4,5};

    // swapAlternate(arr,6);
    // swapAlternate(brr,5);
    // swapAlternateShort(arr,6);
    // swapAlternateShort(brr,5);
    
    return 0;
}