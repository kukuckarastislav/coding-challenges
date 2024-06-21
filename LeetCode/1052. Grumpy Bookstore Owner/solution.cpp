#include <vector>
using namespace std;

/*
Runtime 23ms Beats 66.42%
Memory 34.24MB Beats 82.09%
*/
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();

        int satisfied = 0;
        for(int i = 0; i < n; i++)
            if(!grumpy[i])
                satisfied += customers[i];
        
        int maxSatisfied = satisfied;
        int j = 0;
        for(int i = 0; i < n; i++){

            if(i >= minutes){
                if(grumpy[j])
                    satisfied -= customers[j];
                j++;
            }

            if(grumpy[i])
                satisfied += customers[i];

            maxSatisfied = max(maxSatisfied, satisfied);
        }

        return maxSatisfied;
    }
};