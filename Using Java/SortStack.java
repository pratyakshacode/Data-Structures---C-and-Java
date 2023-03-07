import java.util.Stack;

public class SortStack {

    static void sortStack(Stack<Integer> st){

        if(st.empty()){
            return;
        }

        int element = st.pop();

        sortStack(st);
        insertInSortedOrder(st, element);
    }

    static void insertInSortedOrder(Stack<Integer> st, int element){

        if(st.empty()){
            st.push(element);
            return;
        }

        if(st.peek() > element){
            st.push(element); 
        }

        else {

            int top = st.pop();
            insertInSortedOrder(st, element);
            st.push(top);
        }

    }


    public static void main(String[] args) {

        Stack<Integer> st = new Stack<>();

        st.push(9);
        st.push(5);
        st.push(14);
        st.push(1);
        st.push(20);

        System.out.println(st);

        sortStack(st);
        System.out.println(st);
    }
}
