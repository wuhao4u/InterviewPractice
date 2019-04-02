public class Kadane {
    public int Kadanes(int[] array){
        int n = array.length;
        int[] dp = new int[n];

        //base condition
        dp[0] = array[0];

        int answer = Integer.MIN_VALUE;
        for(int i = 1; i < n; i++){
            dp[i] = Math.max(dp[i - 1], 0) + array[i];
            answer = Math.max(answer, dp[i]);
        }
        return answer;
    }

    public int getMaxSubarraySum(int[] array){
        int currentMax = Integer.MIN_VALUE;
        int totalMax =  Integer.MIN_VALUE;

        for(int i = 0; i < array.length; i++){
            currentMax = Math.max(currentMax, 0) + array[i];
            totalMax = Math.max(totalMax, currentMax);
        }
        return totalMax;
    }
}
