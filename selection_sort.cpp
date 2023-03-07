#include<iostream>
using namespace std;

void Selection_sort(int arr[],int n){

        for(int i=0;i<n;i++){
            
            for(int j=i+1;j<n;j++){
                if(arr[j]<arr[i]){
                    int temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                }
            }
           
        }
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[5]= {10,2,5,3,4};
    Selection_sort(arr,5);

}