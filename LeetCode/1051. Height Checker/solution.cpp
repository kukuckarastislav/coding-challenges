#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        int diff = 0;
        vector<int> expected(heights.begin(), heights.end());
        sort(expected.begin(), expected.end());

        for(int i = 0; i < n; i++)
            if(heights[i] != expected[i])
                diff++;

        return diff;
    }
};