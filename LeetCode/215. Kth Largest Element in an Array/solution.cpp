#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


/*
Runtime
80
ms
Beats
85.27%
of users with C++
Memory
59.90
MB
Beats
70.53%
of users with C++
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> minHeap(nums.begin(), nums.begin() + k);
        
        for(int i = k; i < n; i++){
            if(nums[i] > minHeap.top()){
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }

        return minHeap.top();
    }
};




/*
Runtime
90
ms
Beats
66.77%
of users with C++
Memory
58.70
MB
Beats
86.03%
of users with C++
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k-1];
    }
};




// TLE
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> container;

        for(int x : nums){
            if(container.size() < k){
                container.push_back(x);
                if(container.size() == k)
                    sort(container.begin(), container.end(), greater<int>());    
            }else if(container.back() < x){
                container.back() = x;
                sort(container.begin(), container.end(), greater<int>());
            }
        }

        return container.back();
    }
};