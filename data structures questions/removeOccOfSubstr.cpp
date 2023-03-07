#include<bits/stdc++.h>
using namespace std;

int main(){

    string strg = "abbccaaabbbbbb";
    string substrg = "abb";

    while(strg.length() != 0 && strg.find(substrg)<strg.length()){

        strg.erase(strg.find(substrg),substrg.length());
    }

    cout<< strg ;
    return 0;
}