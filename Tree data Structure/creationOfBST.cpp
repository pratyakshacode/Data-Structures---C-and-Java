#include<bits/stdc++.h>
using namespace std;

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

Node* minVal(Node* root){

    Node * temp = root;

    while(root -> left){
        temp = temp -> left;
    }

    return temp;
}

Node* insertIntoBST(Node* root, int data){

    if(root == NULL){
        root = new Node(data);
        return root;
    }


    if(data > root -> data){
        root -> right = insertIntoBST(root -> right,data);
    }
    else if(data < root -> data){
        root -> left = insertIntoBST(root -> left, data);
    }

    return root;

}

void takeInput(Node* &root){
    int data;
    cin >> data;

    while(data != -1){
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

//DELETION
Node* deleteFromBST(Node* root, int val){

    if(root == NULL){
        return root;
    }

    if(root -> data == val){
        
        // 0 child

        if(root -> left == NULL && root -> right == NULL){
            delete root;
            return NULL;
        }
        // 1 child

        if(root -> left != NULL && root -> right == NULL){
            Node* temp = root -> left;
            delete root;
            return temp;
        }
        if(root -> left == NULL && root -> right != NULL){
            Node * temp = root -> right;
            delete root ;
            return temp;
            
        }
        // 2 child

        else if(root -> left != NULL && root -> right != NULL){

            int mini = minVal(root -> right) -> data;
            root -> data = mini;

            root -> right = deleteFromBST(root -> right, mini);
            return root;
        }
    }

    else if(root -> data < val){
            root -> right = deleteFromBST(root -> right, val);
            return root;
        }

    else{
            root -> left = deleteFromBST(root -> left, val);
            return root;
        }
}

//TRAVERSALS

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

    Node * root = NULL;
    cout << "Enter the data for BST " << endl;
    takeInput(root);
    levelOrderTraversal(root);

    cout << endl << "Inorder Traversal" << endl;
    inorder(root);

    cout << endl <<"preOrder Traversal" << endl;
    preorder(root);

    cout << endl <<  "postOrder Traversal" << endl;
    postorder(root);

    
    root = deleteFromBST(root, 10);
    cout << endl;
    inorder(root);

    cout << endl;
    root = deleteFromBST(root, 5);
    cout << endl;

    inorder(root);
    return 0;
}