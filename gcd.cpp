#include<iostream>
using namespace std;

//By Euclid division lemma

int gcd(int a, int b){
    while(b!=0){
        int rem = a%b;
        a = b;
        b = rem;
    }

    return a;
}

//lcm by relation

int lcm(int a,int b){
    return a*b/gcd(a,b);
}

int main(){

    int a,b,rem;
    cout<<"Enter the two numbers to get gcd and lcm: "<<endl;
    cin>>a>>b;

    int g = gcd(a,b);
    int l = lcm(a,b);

    cout<<"The gcd of two number is: "<<g<<endl;
    cout<<"The lcm of two number is: "<<l<<endl;
    
    return 0;
}