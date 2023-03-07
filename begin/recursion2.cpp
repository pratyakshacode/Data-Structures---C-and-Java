#include<bits/stdc++.h>
using namespace std;

//fibonacci number

int fib(int n){

    if(n == 0 or n == 1){
        return n;
    }

    int ans = fib(n-1) + fib(n-2);

    return ans;

} 

// count the steps to reach the nth stair

int countStairs(int stairs){

    if(stairs < 0) return 0;
    else if(stairs == 0) return 1;

    int ans = countStairs(stairs-1) + countStairs(stairs-2);

    return ans;
}

void sayNumber(int num, string* arr){

    if(num == 0) return;

    int digit = num % 10;
    num = num / 10;

    sayNumber(num, arr);

    cout << arr[digit] << " ";

}

int main(){

    string arr[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

    cout << fib(6) << endl;
    cout << countStairs(5) << endl;
    sayNumber(412,arr);



    return 0;
}