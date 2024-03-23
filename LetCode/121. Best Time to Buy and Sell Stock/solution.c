int maxProfit(int* prices, int pricesSize) {

    int currMaxProfit = 0;
    int minBuyPrice = prices[0];
    
    for(int i = 0; i < pricesSize-1; i++){

        if(i > 0 && prices[i] >= minBuyPrice){
            continue;
        }
        
        minBuyPrice = prices[i];

        for(int j = i+1; j < pricesSize; j++){
            int tempProfit = prices[j] - prices[i];
            if(tempProfit > currMaxProfit){
                currMaxProfit = tempProfit;
            }
        }
    }

    return currMaxProfit;
}