public class Solution {
    public int[] ProductExceptSelf(int[] nums) {
        int n = nums.Length;
        int[] answer = new int[n];

        int[] prefix = new int[n];
        int[] suffix = new int[n];

        Array.Fill(prefix, 1);
        Array.Fill(suffix, 1);

        for(int i = 0; i < n-1; i++){
            prefix[i+1] = prefix[i] * nums[i];
        }

        for(int i = n-1; i > 0; i--){
            suffix[i-1] = suffix[i] * nums[i];
        }

        for(int i = 0; i < n; i++){
            answer[i] = prefix[i] * suffix[i];
        }


       
        return answer;
    }
}