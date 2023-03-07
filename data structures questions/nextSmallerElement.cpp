#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> elements, int n){
    stack<int> s;
    vector<int> ans(n);
    s.push(-1);

    for(int i=n-1; i>=0; i--){

        int curr = elements[i];

        while(s.top() >= curr) s.pop();

        //found the smaller element
        ans[i] = s.top();
        s.push(curr);
    }

   return ans;
}

int main(){

    vector<int> elements = {1,3,5,7,9};
    const int n = elements.size();
    vector<int> ans;

    ans = nextSmallerElement(elements, n);

    for(auto value : ans) cout << value << " ";
    

    return 0;
}