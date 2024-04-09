class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int min_length = n+1;
        int i = 0;
        int j = 0;
        int sum = 0;
        while(j < n){

            sum += nums[j];
            while(sum >= target){
                if(j-i+1 < min_length){
                    min_length = j-i+1;
                }
                sum -= nums[i];
                i++;
            }
            
            j++;
        }

        if(min_length == n+1){
            return 0;
        }
        return min_length;
    }
};