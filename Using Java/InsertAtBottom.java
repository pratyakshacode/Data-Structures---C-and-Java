import java.util.Stack;

public class InsertAtBottom {

    static void insertBottom(Stack<Integer> st, int x){

        if(st.empty()){
            st.push(x);
            return;
        }

        int element = st.peek();
        st.pop();

        insertBottom(st, x);
        st.push(element);
    }

    static void reverse(Stack<Integer> st){

        if(st.empty()){
            return;
        }

        int element = st.pop();

        reverse(st);
        insertBottom(st, element);
    }


    public static void main(String[] args) {
        Stack<Integer> st = new Stack<>();

        st.push(1);
        st.push(2);
        st.push(3);
        st.push(4);
        st.push(5);
        System.out.println(st);

        insertBottom(st, 0);

        System.out.println(st);

        reverse(st);
        System.out.println(st);

    }
}
