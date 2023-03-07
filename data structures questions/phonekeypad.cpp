#include<bits/stdc++.h>
using namespace std;

void solve(string digits, string mapping[], int n, vector<string>& ans, string output, int index){

    if(index >= n){
        ans.push_back(output);
        return;
    }

    int e = digits[index] - '0';
    string value = mapping[e];

    for(int i=0; i<value.length(); i++){
        output.push_back(value[i]);
        solve(digits, mapping, n, ans, output, index+1);
        output.pop_back();
    }

}

int main(){

    string digits = "23";
    int n = digits.length();

    string mapping[10]={"","","abc","def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;

    string output = "";

    solve(digits, mapping, n, ans, output, 0);

    for(auto val : ans){
        cout << val << " ";
    }
    return 0;
}