#include <vector>
using namespace std;




/*
Runtime
27
ms
Beats
90.29%
of users with C++
Memory
7.09
MB
Beats
98.00%
of users with C++
*/
// Dynamic Programming
class Solution {
public:
    static const int MOD = 1000000007;

    int checkRecord(int n) {
        
        int dp[2][2][3] = {0};
        for(int j = 0; j < 2; j++) 
            for(int k = 0; k < 3; k++)
                dp[0][j][k] = 1;

        for(int i = 1; i <= n; i++){
            for(int j = 0; j < 2; j++){             // Absent
                for(int k = 0; k < 3; k++){             // Late
                    long long ans = dp[(i-1)&1][j][0];          // Present
                    ans += (k < 2) ? dp[(i-1)&1][j][k+1] : 0;   // Late
                    ans += (j == 0) ? dp[(i-1)&1][j+1][0] : 0;  // Absent

                    dp[i&1][j][k] = ans % MOD;
                }   
            }
        }

        return dp[n&1][0][0];
    }
};




/*
Runtime
28
ms
Beats
89.68%
of users with C++
Memory
9.63
MB
Beats
89.37%
of users with C++
*/
// Dynamic Programming
class Solution {
public:
    static const int MOD = 1000000007;

    int checkRecord(int n) {
        const int maxN = 100001;
        
        int dp[maxN][2][3] = {0};
        for(int j = 0; j < 2; j++) 
            for(int k = 0; k < 3; k++)
                dp[0][j][k] = 1;

        for(int i = 1; i <= n; i++){
            for(int j = 0; j < 2; j++){             // Absent
                for(int k = 0; k < 3; k++){             // Late
                    long long ans = dp[i-1][j][0];          // Present
                    ans += (k < 2) ? dp[i-1][j][k+1] : 0;   // Late
                    ans += (j == 0) ? dp[i-1][j+1][0] : 0;  // Absent

                    dp[i][j][k] = ans % MOD;
                }   
            }
        }

        return dp[n][0][0];
    }
};





/*
Runtime
1372
ms
Beats
13.09%
of users with C++
Memory
420.24
MB
Beats
23.73%
of users with C++
*/
class Solution {
public:
    static const int MOD = 1000000007;

    int solve(int currIdx, int countA, int countL, int n, vector<vector<vector<int>>>& temp){
        if(currIdx == n)
            return 1;

        if(temp[currIdx][countA][countL] != -1)
            return temp[currIdx][countA][countL];

        int withAnext = 0;
        if(countA == 0)
            withAnext = solve(currIdx + 1, countA + 1, 0, n, temp);

        int withLnext = 0;
        if(countL < 2)
            withLnext = solve(currIdx + 1, countA, countL + 1, n, temp);

        int withPnext = solve(currIdx + 1, countA, 0, n, temp);

        int total = ((withAnext + withLnext) % MOD + withPnext) % MOD;

        temp[currIdx][countA][countL] = total;
        return total;
    }

    int checkRecord(int n) {
        vector<vector<vector<int>>> temp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(0, 0, 0, n, temp);
    }
};