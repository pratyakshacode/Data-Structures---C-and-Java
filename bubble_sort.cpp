#include<iostream>
using namespace std;

    void Bubble_sort(int arr[],int n){

        int counter =1;

        while(counter<n){
            for(int i=0;i<n-counter;i++){
                if(arr[i]>arr[i+1]){
                    int temp = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1] = temp;
                }
            }
            counter++;
        }

        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
    }


int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int array[n];
    
    cout<<"Enter the elements into the array: ";
    for(int i =0;i<n;i++){
        cin>>array[i];
    }
    Bubble_sort(array,n);   

}