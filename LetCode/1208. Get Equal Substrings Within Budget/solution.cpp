#include <string>
using namespace std;


/*
Runtime
0
ms
Beats
100.00%
of users with C++
Memory
8.60
MB
Beats
99.71%
of users with C++
*/
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();

        int i = 0;
        int j = 0;
        int maxSubs = 0;
        int currCost = 0;

        while(j < n){
            currCost += abs(s[j] - t[j]);

            while(currCost > maxCost){
                currCost -= abs(s[i] - t[i]);
                i++;
            }

            if(currCost <= maxCost)
                maxSubs = max(maxSubs, j-i+1);

            j++;
        }

        return maxSubs;
    }
};