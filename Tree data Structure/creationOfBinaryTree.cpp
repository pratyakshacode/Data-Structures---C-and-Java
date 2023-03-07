#include<bits/stdc++.h>
using namespace std;

//creating the node

class Node{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* buildTree(Node* root){

    int data;
    cout << "Enter data: " << endl;
    cin >> data;

    //creating the root node
    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    //creating the left child of root node
     cout << "Enter the data for the left Node of " << data << endl;
     root -> left = buildTree(root -> left);

    //creating the right child of the root node
    cout << "Enter the data for the right Node of " << data << endl;
    root -> right = buildTree(root -> right);

    return root;
}

void levelOrderTraversal(Node* root){

    queue<Node*> q;
    q.push(root);
    q.push(NULL);   // saparator for the enter 

    while(!q.empty()){

        Node * temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;

            if(!q.empty()){
                q.push(NULL);
            }
        }

        else {

            cout << temp -> data << " ";

            if(temp -> left){
                q.push(temp -> left);
            }
            if(temp -> right){
                q.push(temp -> right);
            }

        }
    }
}

void inorder(Node* root){

    if(root == NULL){
        return;
    }

    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);

}

void preorder(Node* root){
    if(root == NULL) return;

    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
}

void postorder(Node* root){
    if(root == NULL) return;

    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << " ";
}

int main(){

    Node* root = NULL;
    root = buildTree(root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    levelOrderTraversal(root);
    cout << endl;
    inorder(root); 
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);

    
    return 0;
}
