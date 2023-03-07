#include<iostream>
using namespace std;

int main(){

    int m,n;
    cout<<"Enter the number of elements: ";
    cin>>m>>n;
    char arr[m][n];

    cout<<"Enter the characters to the Matrix: "<<m<<" x "<<n<<endl;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
        
    //spiral for character to print words

    int rs=0;
    int cs=0;
    int re=m-1;
    int ce = n-1;

    while(rs<=re && cs<=ce){

        for(int col = cs;col<=ce;col++){
            cout<<arr[rs][col]<<" ";
        } 
        rs++;

        for(int row = rs;row<=re;row++){
            cout<< arr[row][ce]<<" ";
        }
        ce--;
    for(int col = ce;col>=cs;col--){
        cout<<arr[re][col]<<" ";
    }
    re--;

    for(int row = re;row>=rs;row--){
        cout<<arr[row][cs]<<" ";
    }
    cs++;
    }

return 0;
    } 






    