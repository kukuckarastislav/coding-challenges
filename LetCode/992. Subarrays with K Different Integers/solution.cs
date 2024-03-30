public class Solution {
    public int SubarraysWithKDistinct(int[] nums, int k) {
        int n = nums.Length;
        int numOfSubsArr = 0;
        Dictionary<int, int> occ = new();

        int i1 = 0;
        int i2 = 0;
        int j = 0;

        while(j < n){

            if(occ.ContainsKey(nums[j])){
                occ[nums[j]] += 1;
            }else{
                occ.Add(nums[j], 1);
            }

            while(occ.Count > k){
                occ[nums[i2]] -= 1;
                if(occ[nums[i2]] <= 0){
                    occ.Remove(nums[i2]);
                }
                i2++;
                i1 = i2;
            }

            while(occ[nums[i2]] > 1){
                occ[nums[i2]] -= 1;
                i2++;
            }

            if(occ.Count == k){
                numOfSubsArr += i2-i1+1;
            }   
            
            j++;
        }


        return numOfSubsArr;
    }
}