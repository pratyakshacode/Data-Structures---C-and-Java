#include<bits/stdc++.h>
using namespace std;

vector<int> reverseVect(vector<int> v){
    
    int i = 0;
    int j = v.size()-1;

    while(i<=j){
        swap(v[i++],v[j--]);
    }

    return v;
}


vector<int> sum(vector<int> &v1, int n,vector<int> &v2,int m){

    vector<int> temp;

    int i = n-1;
    int j = m-1;
    int carry = 0;

    while(i >= 0 && j >= 0){

        int sum = v1[i] + v2[j] + carry;
        carry = sum/10;
        sum = sum % 10;

        temp.push_back(sum);
        i--;
        j--;
    }

    while(i >= 0){

        int sum = v1[i--] + carry;
        carry = sum / 10;
        sum = sum % 10;

        temp.push_back(sum);
    }

    while(j >= 0){
        
        int sum = v2[j--] + carry;
        carry = sum / 10;
        sum = sum % 10;

        temp.push_back(sum);
    }

    while(carry != 0){
        
        int sum = carry;
        temp.push_back(sum);
        carry = carry / 10 ;
    }
   
    return temp;

}

int main(){

    vector<int> v1{5,8,8,8};
    vector<int> v2{9,8,8,8};

    vector<int> ans(sum(v1,4,v2,4));

    ans = reverseVect(ans);

    for(auto value: ans){
        cout<<value<<" ";
    }

    return 0;
}