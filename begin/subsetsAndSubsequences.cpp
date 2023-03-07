#include<bits/stdc++.h>
using namespace std;

void subsets(vector<int>nums, vector<int> output, vector<vector<int>>& ans,  int index){
    

    //base case
    if(index >= nums.size()){
        ans.push_back(output);
        return;
    }

    // excluding 
    subsets(nums,output, ans, index + 1);

    //including the object 
    int object = nums[index];
    output.push_back(object);

    subsets(nums, output, ans, index + 1);

}


int main(){

    vector<int> nums = {1,2,3};

    vector<vector<int>> ans;
    vector<int> output;
    
    subsets(nums, output, ans, 0);

    for(auto value : ans){
        for(int i=0; i<value.size(); i++){
            cout << value[i] << " ";
        }
        cout<<endl;
    }

    

    return 0;
}