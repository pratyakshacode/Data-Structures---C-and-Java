#include<bits/stdc++.h>
using namespace std;

class Node{
    public:

    int data;
    Node* left;
    Node* right;

    Node(int data){
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;

    }
};

class cmp{
    public:

    bool operator()(Node* first, Node* second){
        return first > second;
    }
};

void traverse(Node* root, vector<string>& ans, string temp){

    if(root -> left == NULL && root -> right == NULL){
        ans.push_back(temp);
        return;
    }

    traverse(root -> left , ans, temp + '0');
    traverse(root ->right, ans, temp + '1');

}
int main(){

    int frequency[] = {10,20,36,18,5};
    int n = 5;
    priority_queue<Node*, vector<Node*> ,cmp> pq;

    for(int i=0; i<n; i++){

        Node * temp = new Node(frequency[i]);
        pq.push(temp);
    }

    while(pq.size() > 1){

        auto left = pq.top();
        pq.pop();

        auto right = pq.top();
        pq.pop();

        Node * newNode = new Node(left -> data + right -> data);
        newNode -> left = left;
        newNode -> right = right;

        pq.push(newNode);

    }

    Node* root = pq.top();

    string temp = "";
    vector<string>ans;

    traverse(root, ans, temp);
    
    for(auto element : ans){
        cout << element << " ";
    }

    return 0;
}