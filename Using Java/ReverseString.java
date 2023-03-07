
public class ReverseString {

    public static String reverse(String str, java.util.Stack<Character> st){

        for(int i=0; i<str.length(); i++){

            char ch = str.charAt(i);

            st.push(ch);
        }

        String ans = "";

        while(!st.isEmpty()){
            ans += st.peek();
            st.pop();
        }

        return ans;
    }
    public static void main(String[] args) {
        
        String str = "reverse";

        java.util.Stack<Character> st = new java.util.Stack<>();
        System.out.println(reverse(str, st));
        

        
    }
}
