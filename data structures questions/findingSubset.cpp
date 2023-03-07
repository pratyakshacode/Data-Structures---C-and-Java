#include<bits/stdc++.h>
using namespace std;

//inclusion and exclusion 
void solve(string input, int n, int index, vector<string>& ans, string output){

        if(index >= n){
            ans.push_back(output);
            return;
        }

        // excluding 
        solve(input, n, index+1, ans, output);

        //including

        char element = input[index];
        output.push_back(element);

        solve(input, n, index+1, ans, output);


}
int main(){

    string input = "abc";
    string output="";
    int n = input.length();

    vector<string> ans;

    solve(input, n, 0, ans, output);

    ans.erase(ans.begin());  // empty space

    for(auto val : ans){
        cout << val << " ";
    }
    return 0;
}