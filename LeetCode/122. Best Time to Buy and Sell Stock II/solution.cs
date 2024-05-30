public class Solution {
    public int MaxProfit(int[] prices) {

        int buyPrice = prices[0];
        int cumulativeProfit = 0;

        for(int i = 1; i < prices.Length; i++){
            if(buyPrice < prices[i]){
                cumulativeProfit += prices[i] - buyPrice;
            }

            buyPrice = prices[i];
        }


        return cumulativeProfit;
    }
}