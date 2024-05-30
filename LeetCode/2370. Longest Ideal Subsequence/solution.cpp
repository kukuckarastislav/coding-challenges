#include <string>
using namespace std;

/*
Runtime
28
ms
Beats
97.90%
of users with C++
Memory
11.36
MB
Beats
99.16%
of users with C++
*/

class Solution {
public:
    int longestIdealString(string s, int k) {
        
        int n = s.size();
        int dp[26] = {0};

        for(int i = n-1; i >= 0; i--){
            int ic = s[i] - 'a';

            int left = ic - k;
            if(left < 0) left = 0;

            int right = ic + k;
            if(right > 25) right = 25;

            int maxi = -1;
            for(int j = left; j <= right; j++){
                if(dp[j] > maxi)
                    maxi = dp[j];
            }
            
            dp[ic] = maxi + 1;
        }

        
        int ans = -1;
        for(int i = 0; i < 26; i++){
            if(dp[i] > ans)
                ans = dp[i];
        }
        
        return ans;
    }
};

/*

acfgbd; k=2

a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 	d
0,2,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 	b
0,2,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 	g
0,2,0,1,0,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 	f
0,2,3,1,0,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 	c
4,2,3,1,0,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 	a

ans = max(4,2,3,1,0,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0) // 4

*/