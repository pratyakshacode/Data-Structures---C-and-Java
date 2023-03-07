#include<bits/stdc++.h>
using namespace std;

    void solve(vector<string>& ans, string input, int n, int index){

            cout << input ;
            cout << index << endl;
            if(index >= n-1){
                ans.push_back(input);
                return;
            }

            for(int j = index+1; j<n; j++){
                swap(input[j], input[index]);
                solve(ans, input, n, index+1);
                swap(input[j], input[index]);
            }
    }
int main(){

    string input = "abc";
    int n = input.length();

    string output = "";
    vector<string> ans;

    solve(ans,input, n, 0);

    for(auto val : ans){
        cout << val << " ";
    }

    return 0;
}