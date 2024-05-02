#include <vector>
#include <algorithm>
using namespace std;

/*
Runtime
11
ms
Beats
94.04%
of users with C++
Memory
22.88
MB
Beats
65.86%
of users with C++
*/
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int i = 0;
        int j = n-1;

        while(i < j){

            if(nums[j] <= 0 || nums[i] >= 0)
                break;

            int s = nums[i] + nums[j];

            if(s > 0){
                j--;
            }else if(s < 0){
                i++;
            }else{
                return nums[j];
            }
        }

        return -1;
    }
};






/*
Runtime
20
ms
Beats
51.52%
of users with C++
Memory
26.66
MB
Beats
15.10%
of users with C++
*/
#include <unordered_set>
#include <cstdlib>
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n = nums.size();
        int k = -1;
        unordered_set<int> set;
        
        for(int i = 0; i < n; i++){
            int x = nums[i];
            if(abs(x) > k){
                if(set.count(-1*x)){
                    k = abs(x);
                }
            }
            set.insert(x);
        }

        return k;
    }
};