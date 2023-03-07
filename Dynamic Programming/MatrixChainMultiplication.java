public class MatrixChainMultiplication {

    public int matrixChainMultiplication(int [] arr, int i, int j){

        //base condition 
        if(i >= j) return 0;

        //iteration scheme
        int min = Integer.MAX_VALUE;

        for(int k=i; k<j; k++){

            int tempAns = matrixChainMultiplication(arr, i, k) + matrixChainMultiplication(arr, k+1, j) + arr[i-1] * arr[k] * arr[j];

            min = Integer.min(tempAns, min);

        }

        return min;

    }

    public int usingMemoization(int [] arr, int i, int j, int [][] dp){

        if(i >= j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int min = Integer.MAX_VALUE;

        for(int k=i; k<j; k++){

            int tempAns = usingMemoization(arr, i, k, dp) + usingMemoization(arr, k+1, j, dp) + arr[i-1] * arr[k] * arr[j];

            min = Integer.min(tempAns, min);
        }

        dp[i][j] = min;

        return dp[i][j];
        
    }
    public static void main(String[] args) {
        
        MatrixChainMultiplication mcm = new MatrixChainMultiplication();

        int [] arr = {10,30,5,60};

        System.out.println("Minimum number of operations : " + mcm.matrixChainMultiplication(arr, 1, arr.length - 1));

        int [][] dp = new int[1001][1001];

        for(int i=0; i<dp.length; i++){
            for(int j=0; j<dp[0].length; j++){
                dp[i][j] = -1;
            }
        }

        System.out.println("With memoization : " + mcm.usingMemoization(arr, 1, arr.length - 1, dp));
    }
}
