public class LCS {

    //using recursion 

    public int lcsUsingRecursion(String x, String y, int m, int n){

        if(m == 0 || n == 0){
            return 0;
        }

        if(x.charAt(m-1) == y.charAt(n-1)) return 1 + lcsUsingRecursion(x, y, m-1, n-1);
        else return Integer.max(lcsUsingRecursion(x, y, m-1, n), lcsUsingRecursion(x, y, m, n-1));
        
    }

    public int lcsUsingMemoization(String x, String y, int m, int n, int [][] dp){

        if(m == 0 || n == 0) return 0;

        if(dp[m][n] != -1) return dp[m][n];

        if(x.charAt(m-1) == y.charAt(n-1)) dp[m][n] = 1 + lcsUsingMemoization(x, y, m-1, n-1, dp);
        else dp[m][n] =  Integer.max(lcsUsingMemoization(x, y, m-1, n, dp), lcsUsingMemoization(x, y, m, n-1, dp));

        return dp[m][n];

    }

    public int lcsUsingTabulation(String x, String y){

        int m = x.length(), n = y.length();

        int [][] dp = new int [m+1][n+1];

        for(int i=0; i<dp.length; i++){
            for(int j=0; j<dp[0].length; j++){
                if(i == 0 || j == 0) dp[i][j] = 0;
            }
        }

        for(int i=1; i<dp.length; i++){
            for(int j=1; j<dp[0].length; j++){

                if(x.charAt(i-1) == y.charAt(j-1)) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = Integer.max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[m][n];

    }

    public static void main(String[] args) {
        
        LCS lcs = new LCS();

        String x = "abcdexf";
        String y = "abxfie";
        int m = x.length();
        int n = y.length();

        int [][] dp = new int [m+1][n+1];

        for(int i=0; i<dp.length; i++){
            for(int j=0; j<dp[0].length; j++){
                dp[i][j] = -1;
            }
        }


        System.out.println("Using Recursion : " + lcs.lcsUsingRecursion(x, y, x.length(), y.length()));
        System.out.println("Using Memoization : " + lcs.lcsUsingMemoization(x, y, m, n, dp));
        System.out.println("Using Tabulation : " + lcs.lcsUsingTabulation(x, y));


    }
}