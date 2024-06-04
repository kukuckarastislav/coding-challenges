#include <vector>
#include <queue>
#include <stdlib.h>

using namespace std;



/*
Runtime
171
ms
Beats
84.80%
of users with C++
Memory
141.62
MB
Beats
36.95%
of users with C++
*/
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<vector<int>> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pque; 

        for(int num1 : nums1){
            pque.push({num1 + nums2[0], 0});
        }

        while(k-- && !pque.empty()){
            auto [sum, i2] = pque.top(); pque.pop();

            ans.push_back({sum - nums2[i2], nums2[i2]});

            if(i2 + 1 < n2)
                pque.push({sum - nums2[i2] + nums2[i2 + 1], i2 + 1});
        }

        return ans;
    }
};






/*
Runtime
423
ms
Beats
5.07%
of users with C++
Memory
134.85
MB
Beats
65.41%
of users with C++
*/
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        priority_queue<pair<int, pair<int, int>>> maxHeap; // pairs with smallest sums

        for(int i = 0; i < n1; i++){
            int countPushs = 0;
            for(int j = 0; j < n2; j++){
                int s = nums1[i] + nums2[j];
                if(maxHeap.size() < k){
                    maxHeap.push({s, {nums1[i], nums2[j]}});
                    countPushs++;
                }else if(maxHeap.top().first > s){
                    maxHeap.pop();
                    maxHeap.push({s, {nums1[i], nums2[j]}});
                    countPushs++;
                }else{
                    continue;
                }
            }

            if(countPushs == 0)
                break;
        }
        
        vector<vector<int>> ans;
        while(maxHeap.size()){
            ans.push_back({maxHeap.top().second.first, maxHeap.top().second.second});
            maxHeap.pop();
        }

        return ans;
    }
};






// an attempt to find with four pointers failed
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        priority_queue<pair<int, pair<int, int>>> maxHeap; // pairs with smallest sums

        int i1 = 0, j1 = 0;
        int i2 = 0, j2 = 0;

        while(i1 < n1 || i2 < n2){

            int s1 = (i1 >= n1)? INT_MAX : nums1[i1] + nums2[j2];
            int s2 = (i2 >= n2)? INT_MAX : nums2[i2] + nums1[j1];

            if(s1 <= s2){
                if(maxHeap.size() < k)
                    maxHeap.push({s1, {nums1[i1], nums2[j2]}});
                if(j2 == i2)
                    j1++;
                j2++;
                if(j2 >= n2){
                    i1++;
                    j2 = i1;
                }
            }else{
                if(maxHeap.size() < k)
                    maxHeap.push({s2, {nums1[j1], nums2[i2]}});
                if(j1 == i1)
                    j2++;
                j1++;
                if(j1 >= n1){
                    i2++;
                    j1 = i2;
                }
            }

            if(maxHeap.size() == k) 
                break;
        }

        vector<vector<int>> ans;
        while(maxHeap.size()){
            ans.push_back({maxHeap.top().second.first, maxHeap.top().second.second});
            maxHeap.pop();
        }

        return ans;
    }
};