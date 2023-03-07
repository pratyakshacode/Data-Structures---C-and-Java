#include<iostream>
using namespace std;

int count(int n,int a,int b){
    int c1 = n/a;              //how many numbers are divisible by a 
    int c2 = n/b;              // how many numbers are divisible by b
    int c3 = n/(a*b);          // ,, ,, ,,, ,,, ,,, ,,, ,, ,, ,, both

    return c1+c2-c3;
}
int main(){
    int n,a,b;
    cout<<"Enter the number and the two divisors: ";
    cin>>n>>a>>b;

    int res = count(n,a,b);
    cout<<"Total number divisible by a and b are: " << res;

    return 0;
}