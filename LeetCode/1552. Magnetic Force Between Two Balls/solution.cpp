#include <vector>
#include <algorithm>
using namespace std;


/*
Runtime 121ms Beats 77.71%
Memory 61.48MB Beats 35.79%
*/
class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());

        int lowMag = 1;
        int highMag = position[n-1] - position[0];


        while(lowMag <= highMag){
            int midMag = lowMag + (highMag - lowMag) / 2;

            if(isPossibleToDistributeBalls(position, m, midMag)){
                lowMag = midMag + 1;
            }else{
                highMag = midMag - 1;
            }
        }

        return highMag;
    }

private:
    bool isPossibleToDistributeBalls(vector<int>& position, int m, int space){
        int n = position.size();
        int prev = position[0];
        int i = 1;
        m--;
        while(i < n && m){
            if(position[i] - prev >= space){
                prev = position[i];
                m--;
            }

            i++;
        }

        return m == 0;
    }
};

int main(){

    vector<int> position = {79,74,57,22};
    int m = 4;

    Solution sol;
    int ans = sol.maxDistance(position, m);

    return 0;
}