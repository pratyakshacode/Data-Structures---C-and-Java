
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    ~Node(){
        int data = this -> data ;
        if(next != NULL){
            next = NULL;
            delete next;
        }

        cout << "The Node has been deleted with value " << data << endl;
    }
};

//insertion in the circular linked list
void insertNode( int data, int element, Node* & tail){
    if(tail == NULL){
        Node* newNode = new Node(data);
        newNode -> next = newNode;
        tail = newNode;
    }
    else {

        Node* curr = tail;

        while(curr -> data != element){
            curr = curr -> next;
        }
         Node* newNode = new Node(data);
         newNode -> next = curr -> next;
         curr -> next = newNode;
        tail = curr -> next;
    }
}



void printList(Node* &tail){

        Node* ptr = tail;

        do{
            cout << ptr -> data << " ";
            ptr = ptr -> next;

        } while(ptr != tail);

}

//deletion from the linked list (circular)

void deleteFromlist(int element, Node* & tail){

    Node* check = tail -> next;
    while(check -> data != element){
        check = check -> next;
        if(check == tail){
            cout << "Oops .. The element is not present " << endl;
            
            return;
        }
    }
    if(tail == NULL){
        cout << "Your list has no element .. please Insert the element first "<< endl;
        return;
    }
    else if(tail -> next == tail){
            delete tail;
            tail = NULL;
            cout << "Now the list has been empty " << endl ;
    }
    else{
            Node* curr = tail;
            Node*prev = NULL;

            while(curr -> data != element){
                prev = curr;
                curr = curr -> next;
            }

            if(prev == NULL){
                prev = curr -> next;
            }

            if(curr == tail){
                tail = prev;
            }
            prev -> next = curr -> next;
            curr -> next = NULL;
            delete curr;
    }
}

//checkin whether the linked list is circular or not

bool isCircular(Node*& head){

    if(head == NULL) return true;

    Node* ptr = head-> next;

    while(ptr != NULL && ptr != head){
        ptr = ptr -> next;
    }

    if(ptr == NULL){
        return false;
    }
    else {
        return true;
    }
}

int main(){

    Node* tail = NULL;

   insertNode(1,5,tail);
   insertNode(3,1,tail);
    insertNode(5,3,tail);
    insertNode(7,5,tail);
// deleteFromlist(1,tail);
// deleteFromlist(4,tail);
// // deleteFromlist(4,tail);
   
     printList(tail);
 cout << endl << isCircular(tail);
    return 0;
}