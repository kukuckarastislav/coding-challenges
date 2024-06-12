#include <vector>
using namespace std;


/*
Runtime
0
ms
Beats
100.00%
of users with C++
Memory
9.81
MB
Beats
34.14%
of users with C++
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
    
        int l = 0;
        int m = 0;
        int r = nums.size() - 1;

        while(m <= r){
            if(nums[m] == 2){
                swap(nums[m], nums[r]);
                r--;
            }else if(nums[m] == 0){
                swap(nums[m], nums[l]);
                l++; m++;
            }else{
                m++;
            }
        }
    }
};



/*
Runtime
0
ms
Beats
100.00%
of users with C++
Memory
9.82
MB
Beats
34.14%
of users with C++
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int counter[3] = {0, 0, 0};

        for(int x : nums)
            counter[x]++;

        int x = 0;
        for(int i = 0; i < n; i++){
            while(counter[x] == 0) x++;

            counter[x]--;
            nums[i] = x;
        }
    }
};


int main(){


    vector<int> nums = {2,0,2,1,1,0};
    Solution sol;
    sol.sortColors(nums);


    return 0;
}





/*
Runtime
0
ms
Beats
100.00%
of users with C++
Memory
9.82
MB
Beats
34.14%
of users with C++
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        int idxs[3] = {-1, -1, -1};
        idxs[nums[0]] = 0;

        for(int i = 1; i < n; i++){
            
            int x = nums[i-1];
            int y = nums[i];

            if(idxs[y] == -1)
                idxs[y] = i;

            if(x > y){

                if(x - y == 2 && idxs[1] != -1)
                    x = 1;

                swap(nums[idxs[x]], nums[i]);
                
                idxs[y] = min(idxs[y], idxs[x]);
                if(nums[idxs[x] + 1] == x) idxs[x]++;
                else idxs[x] = i;

                i--;
            }
        }
    }
};


/*
Runtime
0
ms
Beats
100.00%
of users with C++
Memory
9.75
MB
Beats
71.79%
of users with C++
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        int idxs[3] = {-1, -1, -1};
        idxs[nums[0]] = 0;

        for(int i = 1; i < n; i++){

            if(idxs[nums[i]] == -1)
                idxs[nums[i]] = i;

            if(nums[i-1] == 1 && nums[i] == 0){
                // swap first occ of 1 with curr 0
                swap(nums[idxs[1]], nums[i]);
                idxs[0] = min(idxs[0], idxs[1]);
                if(nums[idxs[1] + 1] == 1)
                    idxs[1]++;
                else
                    idxs[1] = i;

                i--;
            }else if(nums[i-1] == 2 && nums[i] == 0){
                if(idxs[1] != -1){
                    swap(nums[idxs[1]], nums[i]);
                    idxs[0] = min(idxs[0], idxs[1]);
                    if(nums[idxs[1] + 1] == 1)
                        idxs[1]++;
                    else
                        idxs[1] = i;
                }else{
                    swap(nums[idxs[2]], nums[i]);
                    idxs[0] = min(idxs[0], idxs[2]);
                    if(nums[idxs[2] + 1] == 2)
                        idxs[2]++;
                    else
                        idxs[2] = i;
                }

                i--;
            }else if(nums[i-1] == 2 && nums[i] == 1){
                swap(nums[idxs[2]], nums[i]);
                idxs[1] = min(idxs[1], idxs[2]);
                if(nums[idxs[2] + 1] == 2)
                    idxs[2]++;
                else
                    idxs[2] = i;

                i--;
            }
            
        }
    }
};
