#include<iostream>
using namespace std;

int count1s(int n){
    int count = 0;
    while(n!=0){
        n = n & n-1;
        count ++;
    }
    return count;
}

int main(){
    int n;
    cout<<"Enter the number : ";
    cin>>n;
int a = count1s(n);
cout<<"The number of ones in binary form are: "<<a<<endl;

cout<<"Enter any key : ";
cin>>n;
return 0;
}