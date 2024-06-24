#include <vector>
#include <stdlib.h>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1    = INT_MAX;
        int profit1 = INT_MIN;
        int buy2    = INT_MAX;
        int profit2 = INT_MIN;

        for(int price : prices){
            buy1    = min(buy1, price);
            profit1 = max(profit1, price - buy1);
            buy2    = min(buy2, price - profit1);
            profit2 = max(profit2, price - buy2);
        }

        return profit2;
    }
};







class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = __INT_MAX__;

        int profit1 = 0;
        int profit2 = 0;

        for(int price : prices){
            if(price > buy){
                int currProfit = price - buy;
                
                if(currProfit > profit1){
                    profit2 = profit1;
                    profit1 = currProfit;
                }else if(currProfit > profit2){
                    profit2 = currProfit;
                }
            }
            
            buy = price;
        }

        return profit1 + profit2;
    }
};