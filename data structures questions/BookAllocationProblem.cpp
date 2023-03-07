
/* In this problem we have the n number of books represented as an array and m number of children.The number of pages on each book are the elements of the book. We have to allocate the books to the children.
There are some conditions of allocating the book. They are:-
1.all the students should have the books 
2. all the books should be allocated to the students
3. the maximum number of pages allocated to the student should be minimum

*/
#include<bits/stdc++.h>
using namespace std;

bool isPossible(int arr[], int m, int n, int mid){

        int stdtCount = 1;
        int pageSum = 0;

        for(int i=0; i<n; i++){
            
            if(pageSum + arr[i] <= mid){
                pageSum += arr[i];
            }
            else{
                stdtCount++;

                if(stdtCount>m || arr[i]>mid){
                    return false;
                }

                pageSum = arr[i];
            }
        }

        return true;
}


int allocateBook(int arr[],int m, int n){
    int s = 0;
    int sum = 0;
    int ans = -1;

    for(int i=0; i<n; i++){
        sum+=arr[i];
    }

    int e = sum;
    int mid = s + (e-s)/2;

    while(s<=e){

        if(isPossible(arr,m,n,mid)){
            ans = mid;
            e = mid-1;
        }
        else s = mid + 1;

        mid = s + (e-s)/2;
    }
        return ans;

}


int main(){

    int arr[5]={10,20,30,40};
    cout<<allocateBook(arr,2,4);
    return 0;
}