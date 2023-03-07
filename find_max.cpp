#include<iostream>
using namespace std;

int main(){
    int max,i,loc,n;
    cout<<"Enter the No. of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements into the array: "<<endl;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    max=arr[0];
    loc = 0;

    for(i=1;i<6;i++){
        if(arr[i]>max){
            loc = i;
        }
        max = arr[loc];
    }
    
    cout<<"The maximum elements is : "<<max;

}