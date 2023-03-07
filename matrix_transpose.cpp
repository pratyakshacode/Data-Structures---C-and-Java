#include<iostream>
using namespace std;

int main(){
    int m,n,temp;
    cout<<"Enter the number of elements: ";
    cin>>m>>n;
    int arr[m][n];

    cout<<"Enter the elements into the array: "<<endl;
    for(int i=0;i<m;i++)
        for(int j=0; j<n; j++)
            cin>>arr[i][j];

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
           if(i<j){
               temp = arr[i][j];
               arr[i][j] = arr[j][i];
               arr[j][i] = temp;
           }
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
        cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;

}