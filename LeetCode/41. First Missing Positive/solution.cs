public class Solution {
    public int FirstMissingPositive(int[] nums) {
        int smallestPostive = int.MaxValue;
        HashSet<int> set = new();
        for(int i = 0; i < nums.Length; i++){
            if(nums[i] > 0){
                set.Add(nums[i]);
                smallestPostive = Math.Min(smallestPostive, nums[i]);
            }
        }

        if(smallestPostive > 1)
            return 1;

        int j = smallestPostive;
        while(true){
            if(set.Contains(j)){
                j++;
            }else{
                return j;
            }

        }
    }
}