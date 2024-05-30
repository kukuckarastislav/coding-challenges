class Solution {
public:
    int trap(vector<int>& height) {
        
        int waterBlocks = 0;
        int n = height.size();

        int topRightH = height[0];
        int topRightHindex = 0;

        for(int i = 1; i < n; i++){
            if(height[i] >= topRightH){
                topRightH = height[i];
                topRightHindex = i;
            }
        }

        int i = 0;
        int j = 1;
        while(j <= topRightHindex){
            if(height[i] > height[j]){
                waterBlocks += height[i] - height[j];
            }else{
                i = j;
            }
            j++;
        }

        i = n - 1;
        j = i - 1;
        while(j >= topRightHindex){
            if(height[i] > height[j]){
                waterBlocks += height[i] - height[j];
            }else{
                i = j;
            }
            j--;
        }


        return waterBlocks;
    }
};