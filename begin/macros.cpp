#include<bits/stdc++.h>
using namespace std;

//going to define the macro
#define PI 3.14           //object macro
#define AREA(a,b) (a*b)         //function macro
#define Compare(a,b) (((a)>(b))?(a):(b))

//chain macros
#define SIGMA value
#define value 2.16

//multiline macros

#define ELEMENT 1, \
                2, \
                3, \
                4, \
                5


int main(){

    int r = 12;
    double area = PI * r * r;
    cout << area << endl;

    cout << AREA(2,3) <<endl;
    cout << Compare(10,8) << endl;
    cout << SIGMA << endl;

    int arr[5] = {ELEMENT};

    for(int i=0; i<5; i++){
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}