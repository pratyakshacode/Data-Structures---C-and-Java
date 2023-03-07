#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallestArea(int arr[], int n){

    stack<int> s;
    vector<int> ans(n);

    s.push(-1);

    for(int i = n-1; i>=0; i--){

        int curr = arr[i];

        while(s.top() != -1 && arr[s.top()] >= curr){
            s.pop();
        }

        //found the smallest area

        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}

vector<int> prevSmallestArea(int arr[], int n){

    stack<int> s;
    vector<int> ans(n);

    s.push(-1);

    for(int i = 0; i<n; i++){

        int curr = arr[i];

        while(s.top() != -1 && arr[s.top()] >= curr){
            s.pop();
        }

        //found the smallest area

        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}



int largestRowArea(int arr[], int n){

    vector<int> next;
    vector<int> prev;
    next = nextSmallestArea(arr,n);
    prev = prevSmallestArea(arr,n);

    int area = INT_MIN;

    for(int i=0; i<n; i++){

        int l = arr[i];

        if(next[i] == -1){
            next[i] = n;
        }

        int b = next[i] - prev[i] - 1;

        int newArea = l * b;

        area = max(area,newArea);
    }

    return area;
}

int main(){

    int maxArea[4][4] = {{0, 1, 1, 0},
                        {1, 1, 1, 1},
                        {1, 1, 1, 1},
                        {1, 1, 0, 0}};
    
    int area = largestRowArea(maxArea[0],4);
    cout << area << endl;

    for(int i=1; i<4; i++){
        for(int j=0; j<4; j++){

            if(maxArea[i][j] != 0){
                maxArea[i][j] = maxArea[i][j] + maxArea[i-1][j];
            }
            else{

                maxArea[i][j] = 0;
            }
        }

        area = max(area,largestRowArea(maxArea[i],4));
    }

    cout << area;


     return 0;
}