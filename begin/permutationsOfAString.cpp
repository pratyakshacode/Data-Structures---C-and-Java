#include<bits/stdc++.h>
using namespace std;

// for the strings

void solve(string nums, vector<string>& ans, int index){

    if(index >= nums.size()){
        ans.push_back(nums);
        return;
    }

    for(int j=index; j<nums.size(); j++){
        swap(nums[index], nums[j]);
        solve(nums, ans, index+1);
        swap(nums[index], nums[j]);
        // nums.pop_back();
    }
}

int main(){

    vector<string> ans;
    string nums;

    cout << "Enter the string: " << endl;
    cin >> nums;

    solve(nums, ans, 0);

    for(auto value : ans) cout << value << " ";

    return 0;
}