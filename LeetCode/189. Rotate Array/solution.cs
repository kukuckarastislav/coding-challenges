public class Solution {
    public void Rotate(int[] nums, int k) {

        if(k >= nums.Length) 
            k = k % nums.Length;

        if(nums.Length == 1 || k <= 0) return;

        int[] temp = new int[k];
        for(int i = 0; i < k; i++){
            temp[i] = nums[nums.Length - k + i];
        }

        for(int i = nums.Length - 1; i >= k; i--){
            nums[i] = nums[i - k];
        }

        for(int i = 0; i < k; i++){
            nums[i] = temp[i];
        }

        return;
    }
}

/*
public class Solution {
    public void Rotate(int[] nums, int k) {

        if(k >= nums.Length) 
            k = k % nums.Length;

        for(int i = 0; i < k; i++){
            int temp1 = nums[i];
            int temp2 = 0;
            int l = 0;
            for(int j = i; j < nums.Length; j += k){
                l = (j + k) % nums.Length;
                Console.WriteLine(i+" "+j+" "+l+" "+temp1+" "+temp2);
                foreach(var item in nums)
                {
                    Console.Write(item.ToString()+" ");
                }
                Console.WriteLine();
                
                temp2 = nums[l];
                nums[l] = temp1;    
                temp1 = temp2;
             
            }
           

        }
    }
}
*/

/*
public class Solution {
    public void Rotate(int[] nums, int k) {

        if(k >= nums.Length) 
            k = k % nums.Length;

        if(nums.Length == 1 || k <= 0) return;

        bool needOneMoreRotation = false;

        if(nums.Length % 2 == 0){
            // even

            if(k % 2 == 0){
                k--;
                needOneMoreRotation = true;
            }

            int i = k;
            int temp1 = nums[k];
            int temp2 = 0;
            int j = 0;
            while(i % nums.Length != 0){

                j = (i+k) % nums.Length;

                temp2 = nums[j];
                nums[j] = temp1;
                temp1 = temp2;

                i += k;
            }
            nums[0] = temp1;


            if(needOneMoreRotation){
                RotateRight(nums);
            }

        }else{
            // odd
            if(k == 1){
                RotateRight(nums);
            }else{
                if(k % 2 != 0){
                    k--;
                    needOneMoreRotation = true;
                }

                int i = k;
                int temp1 = nums[k];
                int temp2 = 0;
                int j = 0;
                while(i % nums.Length != 0){

                    j = (i+k) % nums.Length;

                    temp2 = nums[j];
                    nums[j] = temp1;
                    temp1 = temp2;

                    i += k;
                }
                nums[0] = temp1;


                if(needOneMoreRotation){
                    RotateRight(nums);
                }
            }
        }


    }
    private void RotateRight(int[] nums){
        int temp = nums[nums.Length - 1];
        for(int i = nums.Length - 1; i > 0; i--){
            nums[i] = nums[i - 1];
        }
        nums[0] = temp;
        return;
    }


}
*/