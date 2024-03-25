public class Solution {
    public IList<int> FindDuplicates(int[] nums) {

        IList<int> list = new List<int>();

        for(int i = 0; i < nums.Length; i++){
            int x = Math.Abs(nums[i]);
            if(nums[x-1] < 0){
                list.Add(x);
            }
            nums[x-1] *= -1;
        }
        
        return list;
    }
}