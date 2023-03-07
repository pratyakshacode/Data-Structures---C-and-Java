#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;
    Node * next;

    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }

    ~Node(){

        if(this -> next != NULL){
            this -> next = NULL;
            delete next;
            next = NULL;
        }
    }
};

class Stack{

    public:
    Node* top;
    int count;
    int size;

    Stack(int s){
        this -> size = s;
        top = new Node(-1);
        count = 0;
    }

    void push(int data){

        if(count == size) {
            cout << "Overflow" << endl;
            return;
        }
        Node * newNode = new Node(data);
        newNode -> next = this -> top;
        this -> top = newNode;
        this -> count ++;
    }

    void pop(){

        if(top -> next == NULL || count == 0){
            cout << "Underflow" << endl;
            return;
        }

        cout << this -> top -> data << endl;
        Node* temp = top;

        this -> top = this -> top -> next;
        // cout << top -> data << endl;
        delete temp;
        count --;

    }

    void peak(){

        if(this -> top -> next == NULL){
            cout << "Underflow" << endl;
        }
        else {
            cout << this -> top -> data << endl;
        }
    }
};


int main(){

    Stack s(5);
//adding the elements to the stack

    s.push(1);
    s.peak();

    s.push(2);
    s.peak();

    s.push(3);
    s.peak();

    s.push(4);
    s.peak();

    s.push(5);
    s.peak();

    s.push(6);  //overflow
    s.peak();

//removing the elements from the stack

    s.pop(); // 5
    s.peak();  //4

    s.pop();  //4
    s.peak();  //3
    
    s.pop(); //3
    s.peak(); //2

    s.pop(); //2
    s.peak(); //1

    s.pop(); //1
    s.peak();  // now nothing is present so underflowed;

    s.pop();  // nothing is present and trying to pop hence underflowed


    return 0;
}