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
11.89
MB
Beats
86.61%
of users with C++
*/
/*
    Time: O(log(n*m)) == O(log(n) + log(m))
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = findRowIndex(matrix, target);
        if(row == -1)
            return false;

        return isTargetPresent(matrix[row], target);
    }

    int findRowIndex(vector<vector<int>>& matrix, int target){
        int n = matrix.size();
        int l = 0;
        int r = n - 1;
        int m;

        while(l <= r){
            m = (l + r) / 2;

            if(matrix[m][0] <= target && (m+1 >= n || target < matrix[m+1][0])){
                return m;
            }else if(matrix[m][0] < target){
                l = m + 1;
            }else if(matrix[m][0] > target){
                r = m - 1;
            }
        }

        return r;
    }

    bool isTargetPresent(vector<int>& arr, int target){
        int n = arr.size();

        int l = 0;
        int r = n - 1;
        int m;

        while(l <= r){
            m = l + (r - l) / 2;

            if(arr[m] < target){
                l = m + 1;
            }else if(arr[m] > target){
                r = m - 1;
            }else{
                return true;
            }
        }

        return false;
    }
};