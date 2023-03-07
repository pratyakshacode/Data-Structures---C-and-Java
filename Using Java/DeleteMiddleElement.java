import java.util.Stack;

public class DeleteMiddleElement {

    public static void deleteElement(Stack<Integer> st, int count, int size){

        if(count == size/2){
            st.pop();
            return;
        }

        int element = st.peek();
        st.pop();

        deleteElement(st, count+1, size);

        st.push(element);

    }

    public static void main(String[] args) {
        
        Stack<Integer> st = new Stack<>();
        st.push(1);
        st.push(2);
        st.push(3);
        st.push(4);
        st.push(5);

        System.out.println(st);
        deleteElement(st, 0, st.size());
        System.out.println(st);
    }   

    
}
