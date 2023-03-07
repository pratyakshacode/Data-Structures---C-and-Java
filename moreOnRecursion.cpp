#include<iostream>
using namespace std;
//function to check whether any array is sorted or not
bool check(int arr[],int n){               
    if(n==1)
    return true;

    bool resArray = check(arr+1,n-1);
    return {arr[0]<arr[1] && resArray};
}

//function to print the numbers into decreasing order
void printDec(int n){

    if(n==1){
    cout<<"1"<<" ";
    return;
    }

    cout<<n<<" ";
    printDec(n-1);
}
// functions to print the number into increasing order
void printInc(int n){

    if(n==1){
        cout<<"1"<<" ";
        return;
    }

    printInc(n-1);
    cout<<n<<" ";

}

//function for the first occurence of the number
    int FirstOcc(int arr[],int n,int i,int key){
        if(i==n){
            return -1;
        }
        if(arr[i]==key)
        return i;

        return FirstOcc(arr,n,i+1,key);
    }

//function to check the last occurence of the number 

int LastOcc(int arr[], int n, int i, int key){
    if(i==n)
    return -1;

    int resArr = LastOcc(arr,n,i+1,key);  

    if(resArr!=-1)
        return resArr;

    if(arr[i]==key)
    return i;

return -1;

}
int main(){
    
    int arr[]={1,2,4,3,4,5};
    // cout<<check(arr,5);

    // printDec(5);
    // cout<<endl;
    // printInc(5);
    // cout<<FirstOcc(arr,5,0,2);
    cout<<LastOcc(arr,6,0,8);
    
    return 0;
}