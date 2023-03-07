import java.util.Stack;

public class HistogramArea {

    public static int [] nextSmaller(int heights[]){

        int [] next = new int[heights.length];
        int n = heights.length;

        Stack<Integer> st = new Stack<>();
        st.push(-1);

        for(int i=n-1; i>=0; i--){

            int element = heights[i];

            while(st.peek() != -1 && element < heights[st.peek()]){
                st.pop();
            }

            //smaller element found 

            next[i] = st.peek();
            st.push(i);
        }

        return next;
    }

    public static int [] previousSmaller(int [] heights){

        int [] previous = new int [heights.length];
        int n = previous.length;

        Stack<Integer> st = new Stack<>();
        st.push(-1);

        for(int i=0; i<n; i++){

            int element = heights[i];

            while(st.peek() != -1 && element < heights[st.peek()]){
                st.pop();
            }

            // smaller element found

            previous[i] = st.peek();
            st.push(i);
        }

        return previous;
    }

    public static int histogramArea(int [] heights, int [] next, int [] previous){


        int area = Integer.MIN_VALUE;
        int n = heights.length;

        for(int i=0; i<n; i++){

            int l = heights[i];

            // if(previous[i] == -1) previous[i] = 0;
            if(next[i] == -1) next[i] = n;

            int b = next[i] - previous[i] -1;

            int newArea = l * b;

            area = Integer.max(newArea, area);
        }

        return area;
    }
    public static void main(String[] args) {

        int heights [] = {5,4,3,13};
        
        int [] next = nextSmaller(heights);
        int [] previous = previousSmaller(heights);

        for(var element : next){
            System.out.print(element + " ");
        }


        System.out.println();
        for(var element : previous){
            System.out.print(element + " ");
        }
        System.out.println();

        int ans = histogramArea(heights, next, previous);
        System.out.println(ans);
    }
}
