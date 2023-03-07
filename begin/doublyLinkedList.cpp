#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    Node* prev;
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> prev = NULL;
        this -> next = NULL;
    }

    ~Node(){
        int value = this->data;
        if(next != NULL){
            next = NULL;
            delete next ;
            delete prev;
        }
        cout << "the node has been deleted having the value: " << value << endl;
    }

};

//insertion at beginning of the linked list (doubly)

void insertAtBegin(int data, Node* &head){

    Node* newNode = new Node(data);

    newNode -> next = head;
    head-> prev = newNode;
    head = newNode;
}

// insertion at end of linked list

void insertAtEnd(int data, Node* &tail){

    Node* newNode = new Node(data);

    tail -> next = newNode;
    newNode -> prev = tail;
    tail = newNode;    // or can say that tail = tail -> next

}

//insertion at any position of the linked list

void insertAtPosition(int pos, int data, Node*& head, Node*&tail){

        if(pos == 1){
            insertAtBegin(data, head);
            return;
        }

        Node* ptr = head;
       
        int cnt = 1;

        while(cnt < pos-1){
            ptr = ptr->next;
            cnt ++;
        }

        if(ptr->next == NULL){
            insertAtEnd(data, tail);
            return;
        }

        Node* newNode = new Node(data);
        newNode -> next = ptr -> next;
        newNode -> prev = ptr;
        ptr -> next -> prev = newNode;
        ptr -> next = newNode;
}

//deletion from the doubly linked list 
void deleteFromEnd(Node* & tail){
    
    Node* ptr = tail;
    tail = tail -> prev;
    tail -> next = NULL;
    ptr -> prev = NULL;
    delete ptr;
}
void deleteFromPosition(int pos, Node* & head, Node* &tail){

    if(pos == 1){
        Node* ptr = head;
        head = head -> next;
        ptr -> next = NULL;
        delete ptr;
        }
    int cnt = 1;
    Node* curr = head;
    Node* temp = NULL;

        while(cnt < pos){
            temp = curr;
            curr = curr -> next;
            cnt ++;
        }

        if(curr -> next == NULL) deleteFromEnd(tail);
        else{

            temp->next  = curr -> next;
            curr ->  next -> prev = curr -> prev;
            curr -> prev = NULL;
            curr -> next = NULL;
            delete curr;
        }

   
    }




//printing the linked list

void printList(Node* &head){

    Node* ptr = head;

    while(ptr != NULL){
        cout << ptr -> data << " ";
        ptr = ptr-> next;

    }
}
int main(){

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    //insertion at the beginning
    insertAtBegin(20,head);
    insertAtBegin(30,head);

    //insertion at end
    insertAtEnd(50,tail);
    insertAtEnd(100,tail);
    insertAtEnd(110,tail);
    
    //insertion at any position
    insertAtPosition(2,-1,head, tail);
    insertAtPosition(3,-2,head, tail);
    insertAtPosition(1,-3,head, tail);
    insertAtPosition(1, 4, head, tail);
    // insertAtPosition(11, 120, head, tail);
    insertAtPosition(11, -7, head, tail);
    
    // deleting the nodes from the list
    // deleteFromEnd(head);
    deleteFromPosition(11,head,tail);
    deleteFromPosition(10,head,tail);
    deleteFromPosition(9,head,tail);
    deleteFromPosition(6,head,tail);
    deleteFromPosition(3,head,tail);
    //printing the linked list
    printList(head);
    
    return 0;
}