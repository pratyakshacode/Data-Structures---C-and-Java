#include<bits/stdc++.h>
using namespace std;

class Heap{

    public:
        int size;
        int * arr;

    Heap(int s){
        size = 0;
        arr = new int[s];
        arr[0] = -1;

    }

    void insert(int val){

        size ++;
        int index = size;

        arr[index] = val;

        while(index > 1){

            int parent = index / 2;

            if(arr[index] > arr[parent]) swap(arr[index], arr[parent]);

            index = parent;
        }
    }

    void print(){

        if(size == 0){
            cout << "Nothing to print" << endl;
            return;
        }

        for(int i=1; i<=size; i++){
            cout << arr[i] << " ";
        }
    }

    void deleteNode(){

        if(size == 0){
            cout << "Nothing to delete" << endl;
            return;
        }

        arr[1] = arr[size];
        arr[size] = -1;
        size --;

        int i=1;

        while(i <= size){

            int left = 2 * i;
            int right = 2 * i + 1;

            if(left <= size && arr[left] > arr[i] && arr[left] > arr[right]){
                swap(arr[i], arr[left]);
                i = left;
            }
            else if(right <= size && arr[right] > arr[i] && arr[right] > arr[left]) {
                swap(arr[i], arr[right]);
                i = right;
            }
            else {
                return;
            }
        }
    }
};

int main(){

    Heap h(9);
    h.insert(4);
    h.insert(6);
    h.insert(19);
    h.insert(3);
    h.insert(18);
    h.insert(100);
    h.insert(20);
    h.insert(21);
    

    h.print();
    cout << endl;   //printing the heap
    h.deleteNode();
    h.print(); 
    cout << endl;
    h.deleteNode();
    h.print();
    cout << endl;
    h.deleteNode();
    h.print();
    cout << endl;
    h.deleteNode();
    h.print();
    cout << endl;
    h.deleteNode();
    h.print();
    cout << endl;
    h.deleteNode();
    h.print();
    cout << endl;
    h.deleteNode();
    h.print();
    cout << endl;
    h.deleteNode();
    h.print();
    cout << endl;
    h.deleteNode();
    h.print();
    cout << endl;


    return 0;
}