public class Solution {
    public bool CanJump(int[] nums) {
        if(nums.Length == 1) return true;

        int jumps = 0;

        for(int i = 0; i < nums.Length - 1; i++){

            if(nums[i] > jumps)
                jumps = nums[i];
            
            if(jumps <= 0)
                return false;

            if((i + nums[i]) >= nums.Length - 1)
                return true;

            jumps--;
        }

        return false;
    }
}