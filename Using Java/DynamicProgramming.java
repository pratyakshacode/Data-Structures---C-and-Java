public class DynamicProgramming {

    static int fib(int n){

        if(n == 0 || n == 1) return n;
        return fib(n-1) + fib(n-2);
    }

    static int fibByMemo(int n, int [] dp){

        if(n == 0 || n == 1) return n;

        if(dp[n] != -1) return dp[n];
        
        dp[n] = fib(n-1) + fib(n-2);

        return dp[n];
    }

    static int fibByTabulation(int n){

        int [] dp = new int[n+1];

        dp[0] =  0;
        dp[1] = 1;

        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }

    static int fibByOptimization(int n){

        int prev_2 = 0;
        int prev_1 = 1;
        int curr;

        for(int i=2; i<=n; i++){

            curr = prev_1 + prev_2;
            prev_2 = prev_1;
            prev_1 = curr;
        }

        return prev_1;
    }

    
    public static void main(String[] args) {
    
    System.out.println(fib(7)); 

    int [] dp = new int[8];

    for(int i=0; i<dp.length; i++) dp[i] = -1;

    System.out.println(fibByMemo(7, dp));  
    System.out.println(fibByTabulation(7));
    System.out.println(fibByOptimization(7)); 




    }
}
