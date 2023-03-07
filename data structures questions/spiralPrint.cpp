#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,m,e;
    vector< vector<int> > matrix;

    cout<<"Enter the number of rows and column : ";
    cin >> n >> m;

    for(int i=0; i<n; i++){

        vector<int> temp;

        for(int j=0; j<m; j++){
            cin >> e;
            temp.push_back(e);
        }
        matrix.push_back(temp);
    }

    int row = matrix.size();
    int col = matrix[0].size();

    int startRow = 0;
    int startCol = 0;
    int endRow = row - 1;
    int endCol = col - 1;

    while(startRow < row && endCol < col){

        for(int i = startCol; i <= endCol; i++){
            cout << matrix[startRow][i] <<" ";
        } startRow ++ ;


        for(int i = startRow; i <= endRow; i++){
            cout << matrix[i][endCol] <<" ";
        } endCol -- ;


        for(int i = endCol; i >= startCol; i--){
            cout << matrix[endRow][i] <<" ";
        } endRow --;

        for(int i = endRow; i >= startRow; i--){
            cout << matrix[i][startCol] <<" ";
         } startCol++;
         
    }


    return 0;
}