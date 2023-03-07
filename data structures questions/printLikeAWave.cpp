#include<bits/stdc++.h>
using namespace std;


int main(){

    int arr[3][3] = {{1,2,3},
                     {4,5,6},
                     {7,8,9}};

    int count = 0;
    int row = 0;
    int col = 0;

    while(col < 3){

        if(col%2==0){
            for(int j=0; j<3; j++){
                cout << arr[j][col]<<" ";   
            }
        }

        if(col%2 == 1){
            for(int j=2; j>=0; j--){
                cout << arr[j][col]<<" ";
            }
        }

       col++;
    }


    return 0;
}