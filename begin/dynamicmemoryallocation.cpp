#include<bits/stdc++.h>
using namespace std;

int main(){

    //making the one variable dynamically
/*
    int * ptr = new int ;  //here we will get the pointer of the one integer
    *ptr = 13;
    cout << *ptr;
    delete ptr;

    //making the array of the integer

    int n;
    cin >> n;

    int *arr = new int[10];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    //we maked the array and going to delete it

    delete []arr; */

/*
    making the 2D array(square matrix)
    int n;
    cin >> n;

    int ** matrix = new int*[n];

    for(int i=0; i<n; i++){
        matrix[i] = new int[n];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
        cin >> matrix[i][j];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << matrix[i][j] <<" ";
        }
        cout << endl;
    }

    for(int i=0; i<n; i++){
        delete [] matrix[i];
    }

    delete [] matrix;

    */

    //making the rectangular matrix we have to take the column input also to specify the number of columns

    int row, col;
    cout << "Enter the number of rows and column: ";
    cin >> row >> col;

    int ** matrix = new int*[row];

    for(int i=0; i<row; i++){
        matrix[i] = new int[col];
    }

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin >> matrix [i][j];
        }
    }

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout << matrix [i][j] << " ";
        }
        cout << endl; 
    }


    for(int i=0; i<row; i++){
        delete [] matrix[i];
    }

    delete [] matrix;

        cout<<sizeof(matrix);

    return 0;
}