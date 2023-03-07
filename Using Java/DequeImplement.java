
class MyDeque{
    private int front, rear, n;
    private int [] arr;


    public MyDeque(int size){
        this.front = -1;
        this.rear = -1;

        this.arr = new int [size];
        this.n = size;
    }

    void push(int data){

        if(rear == 0)
        rear++;
        arr[rear] = data;
    }
    void addFront(){

    }

    void addLast(){

    }

    int popFront(){

        return -1;
    }
    int popLast(){
return -1;
    }

    int pop(){
return -1;
    }


    
}

public class DequeImplement {
    public static void main(String[] args) {
        new MyDeque(5);
        

    }
}
