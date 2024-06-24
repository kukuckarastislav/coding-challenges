#include <vector>
#include <queue>
using namespace std;



/*
Runtime 84ms Beats 79.36%
Memory 108.46MB Beats 99.00%
*/
/*
    Time:  O(n)
    Space: O(1)
*/
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int totalFlips = 0;
        int currFlips = 0;

        for(int i = 0; i < n; i++){

            if(i >= k && nums[i-k] == 2)
                currFlips--;

            int currBit = nums[i] ^ (currFlips & 1);
            
            if(currBit == 0){
                if(i+k > n)
                    return -1;

                nums[i] = 2;
                currFlips++;
                totalFlips++;
            }
            
        }

        return totalFlips;
    }
};




/*
Runtime 77ms Beats 93.59%
Memory 110.42MB Beats 63.73%
*/
/*
    Time:  O(n)
    Space: O(k)
*/
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        queue<int> que;

        for(int i = 0; i < n; i++){

            if(!que.empty() && i > que.front())
                que.pop();

            int currBit = nums[i] ^ (que.size() & 1);
            
            if(currBit == 0){
                if(i+k-1 >= n)
                    return -1;

                que.push(i+k-1);
                ans++;
            }
            
        }

        return ans;
    }
};


int main(){

    int k = 1;
    vector<int> nums = {0,1,0};

    Solution sol;
    int ans = sol.minKBitFlips(nums, k);


    return 0;
}



// TLE
/*
    Time:  O(n*n)
    Space: O(1)
*/
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == 0 && i+k <= n){
                for(int j = i; j < i+k; j++){
                    nums[j] ^= 1;
                }
                ans++;
            }
        }

        for(int i = n-1; i >= n-k; i--){
            if(nums[i] == 0)
                return -1;
        }

        return ans;
    }
};