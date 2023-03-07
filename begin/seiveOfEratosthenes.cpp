#include<bits/stdc++.h>
using namespace std;

void seive(int n){

    int count = 0;

    vector<bool> prime(n,true);
    prime[0]=prime[1] = false;

    for(int i=2; i<=n; i++){
        for(int j=2*i; j<=n; j=j+i){
            prime[j]=false;
        }
    }

    for(int i=0; i<=n; i++){
        if(prime[i]) {
            count ++;
            cout << i << " " ;
        }
    }
    cout << endl << count ;
}

int main(){

    int n;
    cout << "Enter the limit of the number: ";
    cin >> n;
    seive(n);

    return 0;
}