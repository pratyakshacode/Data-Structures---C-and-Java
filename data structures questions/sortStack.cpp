#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h> 

void insertInSortedOrder(stack<int>& st, int element){
    
    if(st.empty() || st.top() <= element){
        st.push(element);
        return;
    }
    
    int e = st.top();
    st.pop();
    
    insertInSortedOrder(st, element);
    st.push(e);
    
}
void solve(stack<int>& st){
    
    if(st.empty()){
        return;
    }
    
    int element = st.top();
    st.pop();
    
    solve(st);
    
    insertInSortedOrder(st, element);
}

int main(){

    stack<int> st;
    st.push(5);
    st.push(3);
    st.push(4);
    st.push(1);

    solve(st);

    while(!st.empty()){
        cout << st.top() << endl;
        st.pop();

    }

    return 0;
}