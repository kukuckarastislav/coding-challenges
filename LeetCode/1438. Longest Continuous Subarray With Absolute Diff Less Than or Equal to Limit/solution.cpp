#include <vector>
#include <cmath>
#include <queue>
using namespace std;


/*
Runtime 61ms Beats 85.15%
Memory 54.48MB Beats 81.10%
*/
/*
    Time:  O(n)
    Space: O(n)
*/
// Monotonic Queue
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int maxSub = 0;
        
        deque<int> incDeq;
        deque<int> decDeq;

        int i = 0;
        for(int j = 0; j < n; j++){
            while(!incDeq.empty() && nums[j] < incDeq.back())
                incDeq.pop_back();

            while(!decDeq.empty() && nums[j] > decDeq.back())
                decDeq.pop_back();

            incDeq.push_back(nums[j]);
            decDeq.push_back(nums[j]);

            while(decDeq.front() - incDeq.front() > limit){
                if(nums[i] == incDeq.front()) 
                    incDeq.pop_front();
                
                if(nums[i] == decDeq.front()) 
                    decDeq.pop_front();

                i++;
            }

            maxSub = max(maxSub, j-i+1);
        }

        return maxSub;
    }
};



/*
Runtime 109ms Beats 51.48%
Memory 49.97MB Beats 99.32%
*/
/*
    Time:  best: O(n), worst: O(n*n/2)
    Space: O(1)
*/
// Sliding window
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int maxSub = 0;
        
        for(int i = 0; i < n; i++){
            int currMin = nums[i];
            int currMax = nums[i];
            
            int j = i;
            while(j < n){

                if(limit < max(abs(currMin - nums[j]), abs(currMax - nums[j]))){
                    while(i < j && limit >= abs(nums[i] - nums[j]))
                        i++;

                    while(i < j && limit < abs(nums[i] - nums[j]))
                        i++;

                    i--;
                    break;
                }

                currMax = max(currMax, nums[j]);
                currMin = min(currMin, nums[j]);
                maxSub = max(maxSub, j-i+1);

                j++;
            }

            if(j == n)
                break;
        }

        return maxSub;
    }
};



int main(){

    vector<int> nums = {4,2,2,2,4,4,2,2};
    int limit = 0;

    Solution sol;
    int ans = sol.longestSubarray(nums, limit);

    return 0;
}