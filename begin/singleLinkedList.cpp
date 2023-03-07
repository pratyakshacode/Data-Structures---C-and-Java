#include<bits/stdc++.h>
using namespace std;

//creating the node
class Node{

    public:
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = NULL;
    }

    ~Node(){

       if(this->next != NULL){
        delete next;
        this -> next = NULL;
       }
        
    }

    
};


/* insertion into the linked list */

//insertion at the beginning

void insertAtBegin(int data, Node* &head){

    Node* newNode = new Node(data);
    newNode -> next = head;
    head = newNode;
    

}

//insertion at the end

void insertAtEnd(int data, Node* &tail){

    Node* newNode = new Node(data);
    tail -> next = newNode;
    tail = newNode;

}

//insertion at the middle or at any position

void insertAtPosition(int data, int pos, Node* &head, Node* &tail){
    if(pos == 1){
       insertAtBegin(data,head);
       return;
    }
    
    
    Node* newNode = new Node(data);
    Node* ptr = head;
    int count = 1;

    while(count < pos-1){
        ptr = ptr->next;
        count++;
    }

    if(ptr->next == NULL){
        insertAtEnd(data,tail);
        return;
    }

    newNode -> next = ptr -> next;
    ptr->next = newNode;
}

/*deletion from the linked list*/

//deletion at begin
void deleteAtbegin(Node* &head){

    Node*ptr = head;

    head = head -> next;
    ptr -> next = NULL;
    delete ptr;
    
}

void deleteAtEnd(Node* & head, Node* &tail){
    Node* ptr = head;
    Node* prev = NULL;

    while(ptr -> next != NULL){
        prev = ptr;
        ptr = ptr -> next;
    }

    tail = prev;
    tail -> next = NULL;
    delete ptr;
}


//travesing/printing the linked list 

void printList(Node* &head){
    Node* ptr = head;

    while(ptr != NULL){
        cout << ptr -> data << " ";
        ptr = ptr -> next;
    }

    cout << endl;
}

//reversing the linked list with the different methods

void reverseList(Node*& head){

    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;

    while(curr != NULL){
        forward = curr-> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
        head = prev;
    }

}

void reverseByRecursion1(Node*& head, Node* curr, Node* prev){

        //base case
        if(curr == NULL){
            head = prev;
            return ;
        }

        Node* forward = curr -> next;

        reverseByRecursion1(head, forward, curr);
        curr -> next = prev;

}

Node* reverseByRecursion2(Node* head){

    if(head == NULL || head -> next == NULL){
        return head;
    }

    Node* smallHead = reverseByRecursion2(head -> next);
    head -> next -> next = head;
    head -> next = NULL;

    return smallHead;
}

Node* kReverse(Node* head, int k){

    if(head == NULL){
        return NULL;
    }

    Node* curr = head;
    Node* prev= NULL;
    Node* forward = NULL;
    int count = 0;

    while(curr != NULL && count < k){

        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
        count ++;
    }
    if(forward != NULL)
    head -> next = kReverse(forward, k);

    return prev;


}

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

//finding whether any loop  between the linked list or not

bool loopPresent(Node* &head){

    if(head == NULL) return true;

    map<Node*,bool> check;
    Node* ptr = head;

    while(ptr != NULL){
        if(check[ptr] == true){
            cout << "Loop is present at " << ptr-> data << endl;
            return true;
        }
            check[ptr] = true;
            ptr = ptr -> next;
    }

    return 0;


}

Node* floydCycleDetection(Node* & head){

    if(head == NULL) return NULL;

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && slow != NULL){
        fast = fast-> next;
        if(fast != NULL) fast = fast -> next;

        slow = slow -> next;

        if(fast == slow) return slow; 
    }

    return NULL;
}

Node* startingNode(Node* &head){

    if(head == NULL) return NULL;

    Node* intersection = floydCycleDetection(head);
    Node* slow = head;

    while(intersection != slow){
        intersection = intersection -> next;
        slow = slow -> next;
    }

    return slow;
}

void removeCycle(Node* &head){

    if(head == NULL) return;

    Node* intersect = startingNode(head);

    Node* ptr = intersect;

    while(ptr -> next != intersect){
        ptr = ptr -> next;
    }

    ptr -> next = NULL;
    
}

int main(){

    Node* node1 = new Node(10);

    Node* head = node1;  //start/head of the linked list
    Node* tail = node1;

    //inserting the elements at the beginning
    insertAtBegin(20, head);
    insertAtBegin(30, head);

    //inseting the elements at the end
    insertAtEnd(90,tail);
    insertAtEnd(100,tail);


    //inserting the elements at the middle or at perticular position
    insertAtPosition(50,3,head,tail);
    insertAtPosition(60,4,head,tail);
    insertAtPosition(25,8, head,tail);
    insertAtPosition(-1, 1, head, tail);
    insertAtPosition(-8, 1, head, tail);
    insertAtPosition(11, 11, head, tail);
    insertAtPosition(12, 12,head, tail);
  

    // insertAtEnd(9,tail);

   
    insertAtPosition(10, 10,head, tail);
    cout << "tail data " << tail -> data << endl;
    cout << " head data " << head -> data << endl;
    cout << head -> next -> data << endl;
    tail -> next = head -> next ;

    //printing the linked list
    //printList(head);
//    reverseList(head); 
// reverseByRecursion1(head, head, NULL);
    // Node* ptr = kReverse(head,2);
    // printList(ptr);

    //cout << endl << isCircular(head);
    if(floydCycleDetection(head) == NULL){
        cout << "Not present " << endl;
    }
    else cout << "Present at " << floydCycleDetection(head) -> data << endl;


    cout << "The starting node of the cycle is " << startingNode(head) -> data << endl;

    removeCycle(head);

    if(floydCycleDetection(head) != NULL)
    cout << floydCycleDetection(head) -> data;
    return 0;
}