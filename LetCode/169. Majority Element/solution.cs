public class Solution {
    public int MajorityElement1(int[] nums) {
        Dictionary<int, int> occurrence = new();
        for(int i = 0; i < nums.Length; i++){
            if(occurrence.ContainsKey(nums[i])){
                occurrence[nums[i]] += 1;
            }else{
                occurrence.Add(nums[i], 1);
            }
        }

        int maxOccurrence = 0;
        int majority = 0;
        foreach(KeyValuePair<int, int> pair in occurrence){
            if(maxOccurrence < pair.Value){
                maxOccurrence = pair.Value;
                majority = pair.Key;
            }
        }

        return majority;
    }

    public int MajorityElement2(int[] nums) {
        Array.Sort(nums);
        return nums[nums.Length / 2];
    }

    public int MajorityElement3(int[] nums) {
      int count = 0;
      int candidate = 0;

      foreach(int num in nums){

        if(count == 0) 
            candidate = num;

        if(num == candidate) 
            count++;
        else 
            count--;
      }

      return candidate;
    }
}