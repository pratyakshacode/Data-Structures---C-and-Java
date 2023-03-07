#include<bits/stdc++.h>
using namespace std;

char MaxOccChar(string s){
    
    int chars[26]={0};

    for(int i=0; i<s.length(); i++){
        chars[s[i]-'a']++;
    }

    int maxi = -1;
    int ans = 0;

    for(int i=0; i<26; i++){
        
        if(chars[i] > maxi){
            maxi = chars[i];
            ans = i;
        }
    }

    return 'a' + ans;

}


int main(){

    string s = "Bhavyaaa";
    string s1 = "Pratyaksha";

    cout<<MaxOccChar(s);
    cout<<MaxOccChar(s1);

    return 0;
}