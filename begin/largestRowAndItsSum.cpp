#include<bits/stdc++.h>
using namespace std;

void largestRow(int arr[][3], int n, int m){
    
    int maxSum = -1; 
    int index = -1;

    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=0; j<m; j++){
            sum += arr[i][j];
        }

        if(sum > maxSum){
            maxSum = sum;
            index = i;
        }
    }

    cout<<"The "<<index+1<<" row has the highest sum of "<<maxSum<<endl;
}

void largestCol(int arr[][3], int n, int m){

    int maxSum = -1;
    int index = -1;

    for(int j=0; j<m; j++){
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += arr[i][j];
        }

        if(sum > maxSum){
            maxSum = sum;
            index = j;
        }
    }

    cout<<"The "<<index+1<<" column has the highest sum of "<<maxSum<<endl;
}

int main(){

    int arr[3][3] = {9,8,7,10,11,4,3,2,1};

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<arr[i][j];
        }

        cout << endl;
    }


    largestRow(arr,3,3);
    largestCol(arr,3,3);
    return 0;
}