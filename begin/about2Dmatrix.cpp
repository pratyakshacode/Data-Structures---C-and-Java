#include<bits/stdc++.h>
using namespace std;

void sumOfRow(int arr[][4], int n, int m){

    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=0; j<m; j++){
            sum += arr[i][j];
        }

        cout << sum << " ";
    }
}

void sumOfCol(int arr[][4], int n, int m){


    for(int i=0; i<m; i++){
        
        int sum = 0;
        for(int j=0; j<n; j++){
            sum += arr[j][i];
        }

        cout << sum << " ";
    }
}


int main(){
    
    int arr[3][4] = {0};
    
    for(int row=0; row < 3; row ++){
        for(int col = 0; col < 4; col ++ ){
            cin >> arr[row][col];
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j=0; j<4; j++){
            cout << arr[i][j]<<" ";
        }

        cout<<endl;
    }

    sumOfRow(arr,3,4);
    sumOfCol(arr,3,4);






    return 0;
}