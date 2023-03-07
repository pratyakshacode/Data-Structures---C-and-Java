#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome(string s, int i, int j){

        if(i > j) return true;
        if(s[i] != s[j]) return false;
       
        
        return checkPalindrome(s, i+1,j-1);
}

string reverse(string s, int i, int j){

    if(i > j) return s;

    swap(s[i],s[j]);
    i++;
    j--;

    return reverse(s,i,j);
}



int main(){

    string s = "naman";
    cout << checkPalindrome(s,0,s.length()-1) <<endl;
    string str = "anita";
    cout << reverse(str,0,str.length()-1) << endl;

    return 0;
}