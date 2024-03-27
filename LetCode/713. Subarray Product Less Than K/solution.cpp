class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        if(k <= 1) 
            return 0;

        int n = nums.size();
        int numberOfSubarr = 0;
        double product = 1.0;

        int i = 0;
        int j = 0;

        while(j < n){
            product *= nums[j];
            while(product >= k){
                product /= nums[i];
                i++;
            }
            numberOfSubarr += 1 + (j - i);
            j++;
        }

        return numberOfSubarr;
    }
};


class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int numberOfSubarr = 0;
        double product = 1.0;

        for(int i = 0; i < n; i++){
            product = 1.0;
            for(int j = i; j < n; j++){
                product *= nums[j];
                if(product < k){
                    numberOfSubarr++;
                }else{
                    break;
                }
            }
        }

        return numberOfSubarr;
    }
};


class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> maxFromThisEl(n, 0);

        for(int i = 0; i < n; i++){
            if(nums[i] < k){
                // inc all previus elements by 1 up to first el which is 0
                maxFromThisEl[i] += 1;
                int prod = nums[i];
                int j = i-1;
                while(j >= 0 && maxFromThisEl[j] > 0){
                    prod *= nums[j];
                    if(prod >= k)
                        break;
                    maxFromThisEl[j] += 1;
                    j--;
                }
            }

        }

        int result = 0;
        for(int v:maxFromThisEl)
            result += v;
        
        return result;
    }
};
