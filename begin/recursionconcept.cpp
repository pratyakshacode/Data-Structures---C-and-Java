#include<bits/stdc++.h>
using namespace std;

//factorial of the number 
int factorial(int n){

    if(n==0) return 1;

    // int smallerProb = factorial(n-1);
    // int bigprob = n * smallerProb;

    return n * factorial(n-1);
}

//printing the count to the given number

void printCounting(int n){

    if(n == 0) return;

    printCounting(n-1);
    cout << n << " ";
}

//printing the sum of n natural numbers

int sum(int num){

    if(num == 1) return 1;

    int ans = num + sum(num-1);
    return ans;
}

int multiply(int n, int gap){

    if(n <= 1) return 1;

    int ans = n * multiply(n-gap,gap);
    return ans;

}
int main(){

    cout << factorial(5) << endl;
    printCounting(15); 
    cout << endl;
    cout << sum(5) << endl;
    cout << multiply(5,1);
    return 0;
}