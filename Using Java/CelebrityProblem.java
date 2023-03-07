import java.util.Stack;

public class CelebrityProblem {

    public static boolean celebrity(int [][] persons){

        Stack<Integer> st = new Stack<>();

        int n = persons.length;

        for(int i=0; i<n; i++){
            st.push(i);
        }

        while(st.size() != 1){

            int a = st.pop();
            int b = st.pop();

            if(persons[a][b] == 1){
                st.push(b);
            }
            else st.push(a);
        }

        // got the potential element

        int person = st.peek();

        int row = 0;
        int col = 0;

        for(int i=0; i<persons[person].length; i++){
            if(persons[person][i] == 0) col ++;
        }

        for(int i=0; i<persons.length; i++){
            if(persons[i][person] == 0) row++;
        }
        System.out.println(row );
        System.out.println(col);
        if(row == 1 && col == 3) return true;
        else return false;
    }
    public static void main(String[] args) {
        
        int persons [][] = {
            {0,1,0},
            {0,0,0},
            {0,1,0}
        };

        System.out.println(celebrity(persons));
    }
}
