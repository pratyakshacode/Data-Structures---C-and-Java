#include<bits/stdc++.h>
using namespace std;

// this function will check whether the character of the string is a number or an alphabet

bool valid(char ch){
    if((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <= 'Z') || (ch >='0' && ch <= '9')) return true;

    return false;
}

// function to convert into the valid string

void convertToValid(string &s, string &s2){

    for(int i=0; i<s.size(); i++){
        
        if(valid(s[i])){
            s2.push_back(s[i]);
        }
    }
}

// function to convert the string into the lowercase

void toLowerCase(string &s){

   for(int i=0; i<s.length(); i++) {
    char ch = s[i];
    if(ch >='A' && ch <= 'Z'){
        ch = (ch - 'A') + 'a';
        s[i] = ch;
    }
}
}

//function to check for the palindrome

bool checkPalindrome(string &temp,string &s){

    convertToValid(s,temp);
    toLowerCase(temp);
    

    int i = 0; 
    int e = temp.length()-1;
    
    while(i <= e){

        if(temp[i++] != temp[e--]) return false;

    }


    return true;
}

int main(){

    string s1 = "NA4%^&%$$#m&4aN";
    string s2 = "9^*%^hfueA667AnfB";
    string temp="";
    
  
    if(checkPalindrome(temp,s1)){
        cout<<"Palindrome"<<endl;
    }
    else cout<<"Not a Palindrome"<<endl;

    cout<<checkPalindrome(temp,s2);
    return 0;
}