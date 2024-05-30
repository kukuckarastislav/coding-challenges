public class Solution {
    public int Jump(int[] nums) {

        if(nums.Length == 1) return 0;

        int minJumps = 1;
        int i = 0;

        while(i < nums.Length){
            int jump = i + nums[i];
            if( jump >= nums.Length - 1 ){
                return minJumps;
            }

            int bestNextJumpIndex = 0;
            int bestNextJump = 0;
            for(int j = i+1; j <= jump; j++){
                int nextJump = j + nums[j];
                
                if( nextJump >= nums.Length - 1 ){
                    return minJumps + 1;
                }
                
                if( nextJump >= bestNextJump ){
                    bestNextJumpIndex = j;
                    bestNextJump = nextJump;
                }
            }
            i = bestNextJumpIndex;
            minJumps++;           
        }

        return minJumps;
    }
}