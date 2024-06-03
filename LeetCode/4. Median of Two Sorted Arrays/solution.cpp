#include <vector>
#include <stdlib.h>
using namespace std;


/*
Runtime
11
ms
Beats
98.75%
of users with C++
Memory
94.44
MB
Beats
74.06%
of users with C++
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        if(n > m)   
            return findMedianSortedArrays(nums2, nums1);

        int all = n + m;
        int left = (all+1) / 2;
        int low = 0;
        int high = n;

        int mid1, mid2, l1, l2, r1, r2;

        while(low <= high){
            mid1 = (low + high) / 2;
            mid2 = left - mid1;

            l1 = (mid1 >= 1) ? nums1[mid1 - 1] : INT_MIN;
            l2 = (mid2 >= 1) ? nums2[mid2 - 1] : INT_MIN;
            r1 = (mid1 < n) ? nums1[mid1] : INT_MAX;
            r2 = (mid2 < m) ? nums2[mid2] : INT_MAX;

            if(l1 <= r2 && l2 <= r1){
                if(all % 2) return max(l1, l2);
                else return ((double)max(l1, l2) + min(r1, r2)) / 2.0;
            }else if(l1 > r2){
                high = mid1 - 1;
            }else{
                low = mid1 + 1;
            }
        }

        return -1;
    }
};





/*
Runtime
38
ms
Beats
8.94%
of users with C++
Memory
94.32
MB
Beats
90.30%
of users with C++
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        int i = 0;
        int j = 0;

        int m1 = 0;
        int m2 = 0;

        for(int count = 0; count <= (n+m)/2; count++){
            m2 = m1;
            if(i < n && j < m){
                if(nums1[i] < nums2[j]){
                    m1 = nums1[i++];
                }else{
                    m1 = nums2[j++];
                }
            }else if(i < n){
                m1 = nums1[i++];
            }else{
                m1 = nums2[j++];
            }
        }

        if((n+m) % 2){
            return (double)m1;
        }else{
            return (m1 + m2) / 2.0;
        }
    }
};

