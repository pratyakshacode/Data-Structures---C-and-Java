public class QueueImplement {

        static class MyQueue{
        private int rear, front;
        private int [] arr;
        private int size;

        public MyQueue(int size){

            rear = front = -1;
            this.size = size;
            arr = new int [size];
        }

        void push(int data){

            if(rear == size - 1){
                System.out.println("Queue Overflow");
                return;
            }

            if(front == -1){
                front = 0;
            }
            rear ++;
            arr[rear] = data;
        }

        int pop(){

            if(front == -1 || front == size || front == rear+1){
                System.out.println("Queue Underflow");
                return -1;
            } 

            int element = arr[front];
            arr[front] = -1;
            front++;
            
            return element;
        }

        int front(){
            if(front == -1 || front == size-1 ){
                return -1;
            }
            
            return arr[front];
        }
        
        boolean isEmpty(){

            if(front == -1 || front > rear) return true;
            return false;

        }
    }
    public static void main(String[] args) {
        
        MyQueue q = new MyQueue(5);

        q.push(12);
        q.push(24);
        q.push(36);
        q.push(55);
        q.push(45);
       
        while(!q.isEmpty()){
            System.out.println(q.pop());
        }

        System.out.println(q.isEmpty());
        System.out.println(q.pop());
    }
}
