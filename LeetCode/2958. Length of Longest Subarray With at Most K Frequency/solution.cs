public class Solution {
    public int MaxSubarrayLength(int[] nums, int k) {
        int n = nums.Length;
        int maxSubarr = 0;
        Dictionary<int, int> occurs = new();

        int i = 0;
        int j = 0;

        while(j < n){

            if(occurs.ContainsKey(nums[j])){
                occurs[nums[j]] += 1;
                while(occurs[nums[j]] > k){
                    occurs[nums[i]] -= 1;
                    i++;
                }
            }else{
                occurs.Add(nums[j], 1);
            }

            maxSubarr = Math.Max(maxSubarr, j-i+1);

            j++;
        }

        return maxSubarr;
    }
}