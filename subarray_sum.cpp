//finding the sum of all subarrays of the given array
#include<iostream>
using namespace std;
int main(){
int n;
cout<<"Enter the size of array: ";
cin>>n;
int arr[n];

for(int i=0;i<n;i++){
    cin>>arr[i];
}
int sum=0;
for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
        sum +=arr[j];
        cout<<sum;
    cout<<" ";
    }
    sum = 0;
}
return 0;

}
