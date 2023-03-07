#include<iostream>
using namespace std;

int sum(int n){
    if(n==0)
        return 0;
    
    return n+sum(n-1);
}

int power(int n, int p){
    if(p==0)
        return 1;

    return n*power(n,p-1);
}

int factorial(int n){
    if(n==1)
        return 1;
    
    return n*factorial(n-1);
}

int fibo(int n){
    if(n==0 || n==1)
    return n;

    return fibo(n-1)+fibo(n-2);
}


int main(){

int n,p;
cout<<"Enter the number to get sum upto number: "<<endl;
cin>>n;
cout<<"The sum of n Numbers is: "<<sum(n)<<endl;


cout<<"Enter the number and its power: "<<endl;
cin>>n>>p;
cout<<"n raise to the power p is : "<<power(n,p)<<endl;


cout<<"Enter the number to get the fctorial: "<<endl;
cin>>n;
cout<<"The factorial of the number is: "<<factorial(n)<<endl;


cout<<"Enter the index to get fibonacci number: "<<endl;
cin>>n;
cout<<"The number at "<<n<<"Index is : "<<fibo(n)<<endl;

cout<<"Enter the key to continue: ";
cin>>n;

return 0;
}