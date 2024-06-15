#include <vector>
#include <algorithm>
#include <queue>
using namespace std;



/*
Runtime 2ms Beats 87.85%
Memory 11.11MB Beats 74.85%
*/
// Dynamic Programming, bottom up
/*
    Time: O(n*n / 2)    n is number of rows in triangle
    Space: O(n)
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp = triangle[n-1];

        for(int i = n-2; i >= 0; i--){
            for(int j = 0; j <= i; j++){
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
            }
        }

        return dp[0];
    }
};

int main(){

    Solution sol;
    vector<vector<int>> triangle = {{2}, {3,4}, {6,5,7}, {4,1,8,3}};
    int ans = sol.minimumTotal(triangle);

    return 0;
}


// modify triangle instead of using DP vector
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        for(int i = n-2; i >= 0; i--){
            for(int j = 0; j <= i; j++){
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }

        return triangle[0][0];
    }
};


// BFS Works but Memory Limit Exceeded
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int minSum = __INT_MAX__;
        queue<tuple<int, int, int>> que;
        que.emplace(triangle[0][0], 0, 0);

        while(que.size()){
            auto [currSum, i, j] = que.front(); que.pop();

            if(i == n-1){
                minSum = min(minSum, currSum);
            }else{
                que.emplace(currSum + triangle[i+1][j], i+1, j);
                que.emplace(currSum + triangle[i+1][j+1], i+1, j+1);
            }
        }

        return minSum;
    }
};

