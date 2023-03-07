#include<iostream>
using namespace std;

void primeFactor(int n){
    int prime[50]={0};
    for(int i=2;i<=n;i++){
        prime[i]=i;
    }

    for(int i=2;i<=n;i++){
        if(prime[i]==i){
        for(int j=i*i;j<=n;j+=i){
            prime[j]= i;
        }
    }
}

while(n!=1){
    cout<<prime[n]<<" ";
    n=n/prime[n];

}

}

int main(){
    int n;
    cout<<"Enter the number to find prime factor:-> ";
    cin>>n;

    primeFactor(n);


}