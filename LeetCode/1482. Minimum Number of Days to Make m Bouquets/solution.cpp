#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;




/*
Runtime 108ms Beats 74.81%
Memory 68.94MB Beats 65.37%
*/
// Binary Search
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        if((long long)m*k > n)
            return -1;

        auto [minE, maxE] = minmax_element(bloomDay.begin(), bloomDay.end());
        int low = *minE;
        int high = *maxE;

        while(low < high){

            int mid = low + (high - low) / 2;

            if(canMakeBouquets(bloomDay, m, k, mid)){
                high = mid;
            }else{
                low = mid + 1;
            }
        }

        return low;
    }

private:
    bool canMakeBouquets(vector<int>& bloomDay, int m, int k, int day){
        int bouquets = 0;
        int n = bloomDay.size();

        for(int i = 0; i < n; i++){
            int countAdjFlowers = 0;
            while(i < n && countAdjFlowers < k && bloomDay[i] <= day){
                countAdjFlowers++;
                i++;
            }

            if(countAdjFlowers == k){
                bouquets++;
                i--;
            }

            if(bouquets >= m)
                return true;
        }

        return false;
    }
};


int main(){

    vector<int> bloomDay = {1,10,3,10,2,6,8,7,7};
    int m = 3;
    int k = 2;

    Solution sol;
    int ans = sol.minDays(bloomDay, m, k);

    return 0;
}