#include<bits/stdc++.h>
using namespace std;

class kQueue{

    int * arr;
    int * front;
    int * rear;
    int * next;
    int freespot, size;

    public:
    
    kQueue(int s, int qn){

        size = s;
        arr = new int[s];
        front = new int[qn];
        rear = new int[qn];
        next = new int[s];

        // initializing the freespot 
        freespot = 0;

        // intializing the front and rear
        for(int i=0; i<qn; i++){
            front[i] = -1;
            rear[i] = -1;
        }

        //initializing next array
        for(int i=0; i<s; i++){
            next[i] = i+1;
        }

        next[s-1] = -1;

    }

    void push(int data, int qn){

        if(freespot == -1) {
            cout << "Overflow" << endl;
            return;
        }
        else {

            // in which index we want to fill
            int index = freespot;
            //updating the next of index
            freespot = next[index];

            // going to enter the first element
            if(front[qn - 1] == -1){
                front[index] = 0;
            }
            else{
                    next[rear[qn]] = index;
            }

            next[index] = -1;
            rear[qn - 1] = index;
            arr[index] = data;

        }
    }
    
};
int main(){


    return 0;
}