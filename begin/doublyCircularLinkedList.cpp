#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> prev = NULL;
        this -> next = NULL;
    }

    ~Node(){
        int data = this -> data;
        if(next != NULL){
            next = NULL;
            prev = NULL;
            delete next;
            delete prev;
        }

        cout << " Node has been deleted with data : " << data << endl;
    }
};

//insertion in the list

void insertNode(int data, Node* &tail, int element){

    if(tail == NULL){
        Node* newNode = new Node(data);
        tail = newNode;
        tail -> next = newNode;
        newNode -> prev = newNode;
    }

    else {

        Node* ptr = tail;
        while(ptr -> data != element){
            ptr= ptr-> next;
        }

        Node* newNode = new Node(data);

        newNode -> next = ptr -> next;
        newNode -> prev = ptr;
        ptr -> next -> prev = newNode;
        ptr -> next = newNode;
        // tail = newNode;
    }
}

//deleting the node
//printing the list

void printList(Node* &tail){
    if(tail == NULL){ 
        cout << "List is Empty" << endl; return ;
    }

    else {
        Node* ptr =  tail;

        do {
            cout << ptr -> data << " ";
            ptr = ptr-> next;
        } while(ptr != tail);
    }
}


int main(){

    Node* tail = NULL;
    insertNode(1,tail,4);
    insertNode(2,tail,1);
    insertNode(10,tail,1);
    insertNode(11, tail,2);
    insertNode(12,tail, 11);
    printList(tail);

    return 0;
}