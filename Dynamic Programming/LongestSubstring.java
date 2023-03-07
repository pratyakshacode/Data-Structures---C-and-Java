public class LongestSubstring {

    public int longestSubstring(String x, String y){

        int m = x.length(), n = y.length();

        int [][] dp = new int[m+1][n+1];

        int res = 0;

        for(int i=0; i<dp.length; i++){
            for(int j=0; j<dp[0].length; j++){
                if(i == 0 || j == 0) dp[i][j]= 0;
                else {
                    if(x.charAt(i-1) == y.charAt(j-1)){ 
                        dp[i][j] = dp[i-1][j-1] + 1;
                        res = Integer.max(res, dp[i][j]);
                    }
                    else dp[i][j] = 0;
                }
            }
        }

        return res;
    }

    public StringBuilder printLongestSubstring(String x, String y){

        int m = x.length(), n = y.length();

        int [][] dp = new int[m+1][n+1];

        int res = 0, h = 0, v = 0;

        for(int i=0; i<dp.length; i++){
            for(int j=0; j<dp[0].length; j++){
                if(i == 0 || j == 0) dp[i][j] = 0;
                else {
                     
                    if(x.charAt(i-1) == y.charAt(j-1)){
                        dp[i][j] = 1 + dp[i-1][j-1];

                        if(dp[i][j] > res){
                            res = dp[i][j];
                            h = i;
                            v = j;
                        }
                    }
                    else dp[i][j] = 0;
                }
            }
        }

        String ans = "";
        String temp = "";

        while(h > 0 && v > 0){

           if(x.charAt(h-1) == y.charAt(v-1) && dp[h][v] != 0) temp += x.charAt(h-1);
           else {
            if(ans.length() < temp.length())
                ans = temp;
                temp = "";
           }
           h--; v--;
        }

        return new StringBuilder(ans).reverse();
    }
    public static void main(String[] args) {
        String x = "charger";
        String y = "changer";

        LongestSubstring ls = new LongestSubstring();

        System.out.println(ls.longestSubstring(x, y));
        System.out.println(ls.printLongestSubstring(x, y));
    }
}
