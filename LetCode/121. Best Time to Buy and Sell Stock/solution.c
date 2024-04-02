int maxProfit(int* prices, int pricesSize) {

    int currMaxProfit = 0;
    int i = 0;
    int j = 0;

    while(j < pricesSize){

        int profit = prices[j] - prices[i];
        if(profit <= 0) i = j;
        else if(profit > currMaxProfit) currMaxProfit = profit;
        
        j++;
    }


    return currMaxProfit;
}