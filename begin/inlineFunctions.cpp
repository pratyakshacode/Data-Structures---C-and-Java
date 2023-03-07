#include<bits/stdc++.h>
using namespace std;

//defining the macro
#define SUM(a,b)(a+b);

//The inline functions

inline int compare(int a, int b){
    return (a>b)?a:b;
}

inline int sum(int a, int b){
    return a+b;
}

int main(){

    int ans = compare(3,4);
    cout << ans << endl;
    cout << sum(4, 5) << endl ;
    cout << SUM(4, 6);

    return 0;
}