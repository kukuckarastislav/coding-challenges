public class Solution {
    public long[] MostFrequentIDs(int[] nums, int[] freq) {
        int n = nums.Length;
        long[] ans = new long[n];
        
        Dictionary<int, int> dict = new();
        
        for(int i = 0; i < n; i++){
            
            if(dict.ContainsKey(nums[i])){
                dict[nums[i]] += freq[i];
            }else{
                dict.Add(nums[i], freq[i]);
            }
            
            int maxFreq = 0;
            foreach(var pair in dict){
                if(pair.Value > maxFreq)
                    maxFreq = pair.Value;
            }
            
            ans[i] = maxFreq;
            
        }
        
        return ans;
    }
}