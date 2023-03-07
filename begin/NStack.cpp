#include<bits/stdc++.h>
using namespace std;

class NStack{

    
    int * arr;
    int * top;
    int* next;
    int freespot;
    int n,s;

    public:

    NStack(int S,int N){       //S -> size of main array ......  and  .....  N-> total no. of stack to be implemented

        s = S;
        n = N;

        arr = new int[s];
        top = new int[n];
        next = new int[s];

        memset(top,-1,n);

        for(int i=0; i<s; i++){
            next[i] = i+1;

        }

        next[s-1] = -1;
        freespot = 0;
    }

    void push(int x, int m){    //x -> the element to be inserted   and    m -> stack No.

        //looking for the freespace 
        if(freespot == -1){
            cout << "Stack Overflowed" << endl;
        }

        int index = freespot;

        //inserting the element in stack
        arr[index] = x;

        //updating the free spot

        freespot = next[index];

        //updating next
        next[index] = top[m-1];

        // updating the top

        top[m-1] = next[index];

        cout << endl << "Element inserted " << endl;
    }

    void pop(int m){

            //check for the underflow condition 

            if(top[m-1] == -1){
                cout << "No element Present " << endl;
            }
            int index = top[m-1];

            top[m-1] = next[index];
            next[index] = freespot;

            freespot = index;

            cout << arr[index] << endl;

    }
};
int main(){

   NStack s(6,3);

  s.pop(2);


    return 0;
}