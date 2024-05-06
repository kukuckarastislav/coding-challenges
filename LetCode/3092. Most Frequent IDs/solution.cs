
/*
Runtime
497
ms
Beats
85.00%
of users with C#
Memory
93.94
MB
Beats
86.25%
of users with C#
*/
public class Solution {
    public long[] MostFrequentIDs(int[] nums, int[] freq) {
        int n = nums.Length;
        long[] ans = new long[n];
        
        Dictionary<int, long> dict = new();

        dict.Add(nums[0], freq[0]);
        ans[0] = freq[0];
        int maxNum = nums[0];
        
        for(int i = 1; i < n; i++){
            
            if(dict.ContainsKey(nums[i])){
                dict[nums[i]] += freq[i];
            }else{
                dict.Add(nums[i], freq[i]);
            }
            
            if(maxNum == nums[i] && freq[i] < 0){
                long maxFreq = dict[maxNum];
                foreach(var pair in dict){
                    if(pair.Value > maxFreq){
                        maxFreq = pair.Value;
                        maxNum = pair.Key;
                    }
                }
            }else if(dict[nums[i]] > dict[maxNum]){
                maxNum = nums[i];
            }
            
            
            ans[i] = dict[maxNum];
        }
        
        return ans;
    }
}




// Time Limit Exceeded
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