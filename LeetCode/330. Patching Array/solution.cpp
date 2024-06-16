#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int m = nums.size();
        long missing = 1;
        int patches = 0;
        int i = 0;

        while(missing <= n){
            if(i < m && nums[i] <= missing){
                missing += nums[i];
                i++;
            }else{
                missing += missing;
                patches++;
            }
        }

        return patches;
    }
};