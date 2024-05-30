/*
Runtime
0
ms
Beats
100.00%
of users with C++
Memory
9.25
MB
Beats
91.31%
of users with C++
*/
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        if(tickets[k] == 1)
            return k+1;

        int n = tickets.size();
        int sum = 0;

        for(int i = 0; i < n; i++){
            if(tickets[i] < tickets[k])
                sum += tickets[i];
            else if(i > k)
                sum += tickets[k] - 1;
            else 
                sum += tickets[k];
        }

        return sum;
    }
};