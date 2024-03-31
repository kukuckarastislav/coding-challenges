class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int numOfSubArr = 0;
        bool presentMin = false;
        bool presentMax = false;

        int i = 0;
        int iMin = 0;
        int iMax = 0;
        int j = 0;
        
        while(j < n){

            if(nums[j] == minK){
                iMin = j; 
                presentMin = true;
            }
            if(nums[j] == maxK){
                iMax = j; 
                presentMax = true;
            } 

            if(nums[j] < minK || nums[j] > maxK){
                j++;
                i = j;
                iMin = j;
                iMax = j;
                presentMin = false;
                presentMax = false;
                continue;
            }

            if(presentMin && presentMax){
                if(iMin < iMax){
                    numOfSubArr += iMin-i+1;
                }else{
                    numOfSubArr += iMax-i+1;
                }
            } 

            j++;
        }

        return numOfSubArr;
    }
};