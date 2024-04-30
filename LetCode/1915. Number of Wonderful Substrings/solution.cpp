#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    long long wonderfulSubstrings(string word) {
        
        int n = word.size();
        int cache[1024] = {0};
        cache[0] = 1;
        
        long long cnt = 0;
        int mask = 0;
        
        for(int i = 0; i < n; i++){
            mask ^= (1 << (word[i]-'a'));
            cnt += cache[mask];
            cache[mask]++;
            for(int j = 0; j < 10; j++){
                cnt += cache[mask ^ (1 << j)];
            }
        }

        return cnt;
    }
};