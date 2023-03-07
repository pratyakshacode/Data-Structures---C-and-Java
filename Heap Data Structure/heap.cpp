#include<bits/stdc++.h>
using namespace std;

class heap{
    public:

    int arr[20];
    int size;

    heap(){
        arr[0] = -1;  //because here, we are following the 1 based indexing 
        size = 0;
    }
    
    // INSERTION IN THE HEAP

    void insert(int val){

        size = size+1;
        int index = size;

        arr[index] = val;

        while(index > 1){
            int parent = index / 2;
            
            if(arr[index] > arr[parent]){
            swap(arr[index], arr[parent]);

            index = parent;
            }

            else{
                return;
            }
        }  
    }

    //DELETION IN THE HEAP

    void deleteFromHeap(){

        arr[1] = arr[size];
        arr[size] = -1;
        size --;

        //PLACING THE ROOT TO ITS RIGHT POSITION
        int index = 1;

            while (index < size)
            {
               int leftIndex = 2 * index;
               int rightIndex = 2 * index + 1;

               int largest;

               if(arr[leftIndex] > arr[rightIndex]) largest = leftIndex;
               else largest = rightIndex;

                if(largest < size) swap(arr[largest], arr[index]);
                else return;

                index = largest;

            }
            

    }

    //PRINTING THE HEAP
    void printHeap(){
        for(int i=1; i<=size; i++){
            cout << arr[i] << " ";
        }
    }

};

void heapify(int arr[], int n, int i){

    int largest = i;
    int leftIndex = 2 * i;
    int rightIndex = 2 * i + 1;

   if(leftIndex <= n && arr[leftIndex] > arr[largest]){
    largest = leftIndex;
   }

   if(rightIndex <= n && arr[rightIndex] > arr[largest] ){
    largest = rightIndex;
   }

   if(largest != i){
    swap(arr[largest], arr[i]);
    heapify(arr, n, largest);
   }

}

void heapSort(int arr[], int N)
{
 
 
    // One by one extract an element
    // from heap
    for (int i = N ; i > 1; i--) {
 
        // Move current root to end
        swap(arr[1], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, N,i);
    }
}

// void heapsort(int arr[], int n){
//     if(n < 1){
//         return;
//     }

//     swap(arr[1], arr[n]);
//     n--;
//     heapify(arr, n, n/2);

//     heapsort(arr, n);

// }

int main(){

    heap h;
    h.insert(50);
    h.insert(90);
    h.insert(60);
    h.insert(70);
    h.insert(80);

    h.printHeap();
    h.deleteFromHeap();
    cout << endl;
    h.printHeap();
    h.deleteFromHeap();
    cout << endl;
    h.printHeap();
    h.deleteFromHeap();
    cout << endl;
    h.printHeap();
     cout << endl << "Printing the array by heapifying it: " << endl;

    int arr[6] = {-1,50,90,60,70,80};
    int n = 5;


    for(int i=n/2; i>0; i--){
        heapify(arr,n, i);
    }

    for(int i=1; i<n; i++){
        cout << arr[i] << " ";
    }

    heapSort(arr,n);
    cout << endl << "After heapsort: ";

    for(int i=1; i<n; i++){
        cout << arr[i] << " ";
    } 

    return 0;
}