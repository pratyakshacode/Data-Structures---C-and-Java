public class PrintSCS {

    public void printSCS(String x, String y, int [][] dp){

        int i=x.length(), j= y.length();

        String temp = "";
        while(i > 0 && j > 0){

            if(x.charAt(i-1) == y.charAt(j-1)){
                temp += x.charAt(i-1);
                i--; j--;
            }
            else {
                if(dp[i-1][j] > dp[i][j-1]){
                    temp += y.charAt(j-1);
                }
                else {
                    temp += x.charAt(i-1);
                }
            }
        }

        while(i > 0){
            temp += x.charAt(i-1);
            i--;
        }

        while(j > 0) temp += y.charAt(j-1);


        for(int k=temp.length()-1; k>=0; k--){
            System.out.print(temp.charAt(k));
        }
    }
    public static void main(String[] args) {
        
        PrintSCS scs = new PrintSCS();
        PrintLCS lcs = new PrintLCS();

        String x = "abcdf";
        String y = "abcxf";

        int [][] dp = lcs.lcsMatrix(x, y);

        scs.printSCS(x, y, dp);

    }
}
