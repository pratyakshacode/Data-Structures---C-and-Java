#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        int data = this->data;
        if(next != NULL){
            next = NULL;
            delete next;

        }
    }
};

void printList(Node*& head){

    if(head == NULL){ 
    cout << "list is empty" << endl;
    return;
}

    Node*ptr = head;

    do{
        cout << ptr -> data << " ";
        ptr = ptr-> next;

    } while(ptr != NULL && ptr != head);

    cout << endl;
    
}

    
    void insertNode(int data,int pos, Node* &head){

        if(head == NULL){
            Node* newNode = new Node(data);
            head = newNode;
            return;
        }
        Node* ptr = head;

        int count = 1;

        while(count < pos - 1){
            ptr = ptr -> next;
            count++;
        }

        Node* newNode = new Node(data);
        newNode -> next = ptr -> next;
        ptr -> next = newNode;
    }

    // removing the duplicates from the linked list 

    void removeDuplicates(Node* head){

        if(head == NULL) return;

        Node * ptr = head;

        while(ptr != NULL){

            if((ptr -> next != NULL) && (ptr -> data == ptr -> next -> data)){

                Node* toDelete = ptr -> next;
                ptr -> next = ptr -> next -> next;
                delete toDelete;
            }
            else {
                ptr = ptr -> next;
            }
        }

    
    }

    void removeUnsorted(Node* head){
        
        if(head ==NULL) return;

        unordered_map < int , bool> visited;

        Node* curr = head;
        Node* prev = NULL;

        while(curr != NULL){

            if(visited[curr -> data] == true){

                Node* toDelete = curr;
                prev -> next = curr -> next;
                curr = curr -> next;
                delete toDelete;
            }

            else{
                visited[curr -> data] = true;
                prev = curr;
                curr =  curr -> next ;
            }
        }

    }

    void makeCircular(Node* &head){

        Node* ptr = head;
         while(ptr -> next != NULL) ptr = ptr -> next;

         ptr -> next = head;
        //  cout << ptr -> next -> data << endl;

    }


    void removeCircular(Node* &head){

        Node* ptr = head;
        while(ptr -> next != NULL) ptr = ptr-> next;

        ptr -> next = NULL;
    }

        


int main(){

    int n,data,pos;

    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;

    cout << "How many Nodes You want to insert : " << endl;
    cin >> n;

    for(int i=0; i<n; i++){
        cout << "Enter data : " ;
        cin >> data;
        cout << "Enter position : ";
        cin >> pos;
        insertNode(data,pos, head);
    }

    // makeCircular(head);
    printList(node1);
    // removeDuplicates(head);
    // removeUnsorted(head);
    makeCircular(head);
    
    printList(head);
    return 0;
}


