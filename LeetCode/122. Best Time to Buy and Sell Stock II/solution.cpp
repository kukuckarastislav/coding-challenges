#include <vector>
using namespace std;


/*
Runtime 3ms Beats 88.15%
Memory 15.37MB Beats 92.62%
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = __INT_MAX__;
        int profit = 0;

        for(int price : prices){
            if(price > buy)
                profit += price - buy;
            
            buy = price;
        }

        return profit;
    }
};