#include<bits/stdc++.h>
using namespace std;

class Queue{
    int * arr;
    int front;
    int rear;
    int size;
public:

    Queue(int s){
        size = s;
        arr = new int[size];
        front = 0;
        rear = 0;
    }
    
    void enqueue(int data){

        if(rear == size){
            cout << "Queue Overflowed .." << endl;
        }
        else{
            arr[rear] = data;
            rear++;
        }
    }

    void dequeue(){
        if(front == rear){
            cout << "Queue Underflowed .." << endl;
        }

        else{
            int val = arr[front];
            arr[front] = -1;
            front ++;

            if(front == rear){
                front = 0;
                rear = 0;
            }
        }
    }

    bool isEmpty(){
        if(rear == front) return true;
        else return false;
    }

    int qfront(){
        if(front == rear){
            cout << "Nothing Present"<< endl;
            
        }
        else return arr[front];
        return -1;
    }
};
int main(){

    Queue q(5);
    q.enqueue(5);
    cout << q.qfront() << endl;
    q.enqueue(13);
     cout << q.qfront() << endl;
    q.enqueue(16);
     cout << q.qfront() << endl;
    q.enqueue(18);
     cout << q.qfront() << endl;
    q.enqueue(23);
    cout << q.qfront() << endl;
    
    q.enqueue(12);

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout << q.qfront() << endl;
    q.dequeue();
    cout << q.qfront() << endl;
    q.enqueue(100);
    cout << q.qfront() << endl;



    return 0;
}