#include<iostream>
using namespace std;

int main(){

    int mx=0,arr[5]={12,5,3,2,1};
    
    for(int i =0;i<5;i++){
        mx = max(mx,arr[i]);    
    }
    cout<<mx;
    return 0;

}