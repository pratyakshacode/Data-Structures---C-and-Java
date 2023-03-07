#include<bits/stdc++.h>
using namespace std;

void solve(vector<string>& ans, string digits, int index, string output,string mapping[]){

        if(index >= digits.length()){
            ans.push_back(output);
            return;
        }

        int number = digits[index] - '0';
        string value = mapping[number];

        for(int i=0; i<value.size(); i++){
            output.push_back(value[i]);
            solve(ans, digits, index + 1, output, mapping);
            output.pop_back();
        }

}
int main(){

    string digits;
    cout << "Enter the digits of the dialer pad from 2-9: " << endl;
    cin >> digits;
    int index = 0;
    string output;
    vector<string>ans;
    string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    if(digits.length() == 0){
        cout << " empty string ..... ";
        return 0;
    }
    solve(ans,digits, index, output, mapping);

    for(auto value : ans){
        cout << value << " ";
    }
    return 0;
}