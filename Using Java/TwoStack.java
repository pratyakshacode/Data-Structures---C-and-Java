
class Stack{
    int [] arr;
    private int top1, top2, size;

    public Stack(int size){
        arr = new int[size];
        top1 = -1;
        top2 = size;
        this.size = size;
    }

    public void push_1(int data){

        if(top2 - top1 <= 1){
            System.out.println("Stack Underflow");
            return;
        }
        arr[++top1] = data;
    }
    public void push_2(int data){

        if(top2 - top1 <= 1) {
            System.out.println("Stack Overflow");
            return;
        }

        arr[--top2] = data;
    }

    public int pop_1(){

        if(top1 == -1){
            return -1;
        }
        return arr[top1--];
    }

    public int pop_2(){

        if(top2 == size){
            return -1;
        }

        return arr[top2++];
    }

    public int top_1(){
        
        if(top1 == -1) return -1;
        return arr[top1];
    }

    public int top_2(){
        if(top2 == size) return -1;

        return arr[top2];
    }


}
class TwoStack {
    public static void main(String[]args){

        Stack st = new Stack(6);
        st.push_1(12);
        st.push_2(89);
        st.push_1(44);
        st.push_2(15);

        System.out.println(st.top_1());
        System.out.println(st.top_2());

        st.push_1(15);
        st.push_2(0);
        st.push_2(445);

        System.out.println(st.top_1());
        System.out.println(st.top_2());

    }
}