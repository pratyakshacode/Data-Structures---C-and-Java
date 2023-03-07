#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> heights, int n){

    stack<int> s;
    s.push(-1);
    vector<int> next(n);

    for(int i=n-1; i>=0; i--){

        int curr = heights[i];
        while(s.top() != -1 && heights[s.top()] >= curr){
            s.pop();
        }

        //here find the smaller element

        next[i] = s.top();
        s.push(i);
    }

    return next;

}

vector<int> prevSmallerElement(vector<int> heights, int n){

    stack<int> s;
    s.push(-1);
    vector<int> prev(n);

    for(int i=0; i<n; i++){

        int curr = heights[i];

        while(s.top()!= -1 && heights[s.top()] >= curr){
            s.pop();
        }

        // found prev next

        prev[i] = s.top();
        s.push(i);
    }

    return prev;
}
int main(){

    vector<int> heights = {1,4,6,4,1,5};
    const int n = heights.size();

    vector<int> next;     // will hold all the next greater elements for each element
    vector<int> prev;       // will hold all the prev greater elements for each element

    next = nextSmallerElement(heights, n);  // will provide the last index to go
    prev = prevSmallerElement(heights, n);  // will provide the first index to go

    int area = INT_MIN;

    for(int i=0; i<n; i++){

        int l = heights[i];

        if(next[i] == -1){
            next[i] = n;        //the case where no smaller element is present and it takes the whole breadth of the base
        }
        int b = next[i] - prev[i] - 1;

        int newArea = l * b;

        area = max(area, newArea);
    }

    cout << "The maximum area of the rectangle in Histogram is : " << area;

    return 0;
}