// this is the program for finding the exponential of the number quickly in O(log n)
// follows the divide and conquer approach
// we only do the square of the number and if the number is odd we have to multiply the number externally

#include<bits/stdc++.h>
using namespace std;

int fastExponent(int num, int power){

    int res = 1;

    while(power > 0){

        if(power & 1){

            res = res * num;
        }
        
        num = num * num;
        power = power >> 1;
    }

    return res;
}

int main(){

    int num, power;

    cout<<"Enter the number and its power: " << endl;
    cin >> num >> power;

    cout << fastExponent(num,power);


    return 0;
}