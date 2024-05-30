class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long int numberOfSubsarr = 0;
        int currNumberOfEl = 0;
        int maxEl = 0;
        for(int v:nums){
            if(v > maxEl) maxEl = v;
        }
 
        int i = 0;
        int j = 0;
 
        while(j < n){
            if(nums[j] == maxEl)
                currNumberOfEl++;
 
            while(currNumberOfEl >= k){
                if(nums[i] == maxEl) 
                    currNumberOfEl--;
                i++;
                numberOfSubsarr += (n-j);
            }
            j++;
        }
 
 
        return numberOfSubsarr;
    }
};