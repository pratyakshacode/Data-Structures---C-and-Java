class NStack{

    private int size;
    private int [] arr;
    private int freespot;
    private int [] next;
    private int [] top;

    NStack(int N){

        size = 4 * N;
        arr = new int [size];
        freespot = 0;

        //intializing the top array

        top = new int [N];
        for(int i=0; i<N; i++){
            top[i] = -1;
        }

        //initializing the next array

        next = new int[size];
        for(int i=0; i<size; i++){
            next[i] = i+1;
        }

        next[size-1] = -1; //last element cannot have next

    }

    void push(int stack, int element){

        if(stack < 1){
            System.out.println("1 based Indexing Here");
            return;
        }
        if(freespot == -1) {
            System.out.println("Stack Overflow");
            return;
        }

        int index = freespot;
        freespot = next[index];

        arr[index] = element;

        next[index] = top[stack-1];
        top[stack-1] = index;
    }

    int pop(int stack){

        if(stack < 1){
            System.out.println("1-based indexing here");
            return -1;
        }
        if(top[stack -1] == -1 ){
            System.out.println("Nothing present");
            return -1;
        }

        int index = top[stack-1];
        top[stack-1] = next[index];

        next[index] = freespot;
        freespot = index;

        return arr[index];
    }
    
    int peek(int stack){
        return arr[top[stack-1]];
    }

    boolean isEmpty(int stack){

        if(stack < 1) return false;
        return top[stack-1] == -1;
    }
    
}

public class NStackImplement {
    
    public static void main(String[] args) throws Exception{
        
        NStack stack = new NStack(3);
        System.out.println(stack.isEmpty(1));
        System.out.println(stack.isEmpty(2));
        System.out.println(stack.isEmpty(3));
       
       stack.push(1, 12);
       stack.push(1, 13);
       stack.push(1, 15);

       System.out.println(stack.peek(1));
       stack.pop(1);
       System.out.println(stack.peek(1));
       stack.push(2, 22);
       stack.push(2, 23);
       stack.push(2, 24);
       stack.push(1,100);
       stack.push(2,45);
       stack.push(1, 77);

       System.out.println("top of 1st : " + stack.peek(1));
       System.out.println("top of 2nd : " + stack.peek(2));

    }
}
