#include<iostream>
using namespace std;

void primeFind(int n){ 
    int prime[50]={0};

    for(int i=2;i<=n;i++){         //the loop will be started from the 2 as 2 is the first prime number 
        for(int j=i*i;j<=n;j+=i){  
            prime[j]=1;            //this loop will start from the num^2 and mark all the multiples of the number(i)
        } 
        
        //j=3^2=6, j+=3=> j=6,j=9,j=12,j=15 ............... 
        //unmarked numbers will be those numbers that are not the multiple of any number and hence they will be the prime numbers
    }
    
    for(int i=2;i<=n;i++){    //this loop will check the unmarked numbers and they will be the prime numbers
        if(prime[i]==0){
            cout<<i<<" ";
        }
        
    }

}
int main(){

    int num;
    cout<<"Enter the limit for number: ";
    cin>>num;
    
    primeFind(num);

}