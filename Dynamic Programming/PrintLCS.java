public class PrintLCS {

    public int [][] lcsMatrix(String x, String y){

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
        return dp;
    }

    public void printLCS(String x, String y){

        int [][] matrix = lcsMatrix(x, y);

        int i=x.length(), j = y.length();

        String temp = "";

        while(i > 0 && j > 0){

            if(x.charAt(i-1) == y.charAt(j-1)){
                temp += x.charAt(i-1);
                i--; j--;
            }
            else {

                if(matrix[i-1][j] > matrix[i][j-1]) i--;
                else j--;
            }
        }

        for(int k=temp.length()-1; k>=0 ; k--){
            System.out.print(temp.charAt(k));
        }
    }

    
    public static void main(String...args){

        String x = "abcdf";
        String y = "abxyfc";

        PrintLCS lcs = new PrintLCS();

        lcs.printLCS(x, y);
    }
}
