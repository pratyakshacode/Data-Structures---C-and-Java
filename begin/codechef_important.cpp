#include<bits/stdc++.h>
using namespace std;

bool solve(int arr[], int n){

    int i=0; 
    int j=1;
    int k=2;

    while (k < n){
        cout << arr[i] << " " <<  arr[j] <<" "<< arr[k] << endl;
        if((arr[i] + arr[j] +arr[k]) % 10 == 3){ 
            cout << "The ans is " << arr[i] <<" " << arr[j] << " " << arr[k] << endl;
            return true;}
        else k++;
    }
    k = k-1;

    while (j < n-1){
        cout << arr[i] << " " <<  arr[j] <<" "<< arr[k] << endl;
          if((arr[i] + arr[j] +arr[k]) % 10 == 3){ 
            cout << "The ans is " << arr[i] <<" " << arr[j] << " " << arr[k] << endl;
            return true;}
        else j++;
    }

    j = j-1;
    
    while (i < n-2){
        cout << arr[i] << " " <<  arr[j] <<" "<< arr[k] << endl;
          if((arr[i] + arr[j] +arr[k]) % 10 == 3){ 
            cout << "The ans is " << arr[i] <<" " << arr[j] << " " << arr[k] << endl;
            return true;}
        else i++;
    }
    
    
    return false;

}
int main(){

    int arr[5]={20,22,59,51,41};
    if(solve(arr,5)) cout << "Yes" << endl;
    else cout << "No" << endl;


    return 0;
}