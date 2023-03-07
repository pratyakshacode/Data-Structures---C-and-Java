#include<iostream>
using namespace std;

//reversing the string 
void reverse(string s){
    if(s.length()==0)
    return;

    char c = s[0];
    string ros = s.substr(1);

    reverse(ros);
    cout<<c;
}

//replacing the pi with 3.14

void replace(string s){

    if(s.length()==0)
    return;

    if(s[0]=='p' && s[1]=='i'){
    cout<<"3.14";
    replace(s.substr(2));
    }
    else{
    cout<<s[0];
    replace(s.substr(1));
    }
}

//tower of Hanoi
// The result will be of 2^n - 1

void Tower(int n, char src,char dest,char aux){

    if(n==0)
    return;

    Tower(n-1,src,aux,dest);
    cout<<"Move from "<<src<<" to "<<dest<<endl;
    Tower(n-1,aux,dest,src);
}

//Removing the duplicate items from the string 
// eg aaaabbbbcccdd --> abcd
string Remove(string s){
    if(s.length()==0)
    return s;

    char f = s[0];
    string ans = Remove(s.substr(1));

    if(f == ans[0])
    return ans;

    return f+ans;    
}

int main(){

    // reverse("aabbccdd");
    // replace("pippiiipi");
    // Tower(4,'A','B','C');
    cout<<Remove("aaaabeebbbcccdd");

    return 0;
}