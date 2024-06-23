#include <vector>
using namespace std;


class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();        
        int numOfFlipping = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == 0 && (numOfFlipping % 2 == 0) ||
               nums[i] == 1 && (numOfFlipping % 2 == 1)){
                numOfFlipping++;
            }
        }

        return numOfFlipping;
    }
};