public class PalindromePartitioning {

    public boolean isPalindrome(String s){

        int i = 0, j = s.length()-1;

        while(i <= j){
            if(s.charAt(i) != s.charAt(j)) return false;
            i++; j--;
        }

        return true;
    }
    public int partitioning(String s, int i, int j){

        if(i >= j) return 0;
        if(isPalindrome(s.substring(i, j+1))) return 0;

        int mn = Integer.MAX_VALUE;

        for(int k=i; k<j; k++){

            int tempAns = 1 + partitioning(s, i, k) + partitioning(s, k+1, j);
            mn = Integer.min(tempAns, mn);
        }

        return mn;
    }

    public int partitioningUsingDP(String s, int i, int j, int [][] dp){

        if(i >= j) return 0;
        if(isPalindrome(s.substring(i, j+1))) return 0;
 
        if(dp[i][j] != -1) return dp[i][j];

        int mn = Integer.MAX_VALUE;

        for(int k=i; k<j; k++){
            
            int temp1, temp2;
            if(dp[i][k] != -1) temp1 = dp[i][k];
            else temp1 = partitioningUsingDP(s, i, k, dp);

            if(dp[k+1][j] != -1) temp2 = dp[k+1][j];
            else temp2 = partitioningUsingDP(s, k+1, j, dp);

            int tempAns = 1 + temp1 + temp2;
            mn = Integer.min(tempAns, mn);
        }

        dp[i][j] = mn;
        return mn;
    }
    public static void main(String[] args) {
        
        PalindromePartitioning p = new PalindromePartitioning();
        String s = "nitik";
        System.out.println(p.isPalindrome(s));

        System.out.println("Palindromic Partitioning : " + p.partitioning(s, 0, s.length() - 1));

        int [][] dp = new int[10][10];

        for(int i=0; i<dp.length; i++){
            for(int j=0; j<dp[0].length; j++){
                dp[i][j] = -1;
            }
        }
        System.out.println("Palindromic Partitioning using DP : " + p.partitioningUsingDP(s, 0, s.length() - 1, dp));
    }
}
