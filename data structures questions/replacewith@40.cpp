#include<bits/stdc++.h>
using namespace std;

string replaceSpace(string s){

    string temp = "";

    for(int i=0; i<s.length(); i++){

        if(s.at(i) == ' '){
            temp.push_back('|');
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
            temp.push_back('|');
        }

        else temp.push_back(s[i]);
    }

    return temp;
}
int main(){

    string s = "hey there i am using whatsapp";
    
    cout << replaceSpace(s);
   

    return 0;
}