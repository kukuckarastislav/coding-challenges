/*
Runtime
0
ms
Beats
100.00%
of users with C++
Memory
7.96
MB
Beats
99.26%
of users with C++
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int i = 0;
        int j = 0;

        int k = 0;

        int r = 0;
        vector<int> res;

        while(k < min(n,m)){

            while(j < n-k){
                res.push_back(matrix[i][j]);
                j++;
            }
            j = n-k-1;

            i++;
            while(i < m-k){
                res.push_back(matrix[i][j]);
                i++;
            }
            i = m-k-1;

            j--;
            while(j >= k){
                res.push_back(matrix[i][j]);
                j--;
            }
            j = k;

            k++;
            i--;
            while(i >= k){
                res.push_back(matrix[i][j]);
                i--;
            }
            i = k;
            j = k;
        }

        while(res.size() > n*m) res.pop_back();

        return res;
    }
};