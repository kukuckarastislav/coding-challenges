#include <vector>
#include <algorithm>
#include <priority_queue>
using namespace std;


class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        
        vector<pair<double, int>> ratio;
        int n = quality.size();
        
        for (int i = 0; i < n; ++i) {
            ratio.emplace_back((double)wage[i]/quality[i], (double)quality[i]);
        }
            
        sort(ratio.begin(), ratio.end());
        priority_queue<int> maxHeap;
        int qualitySum = 0;
        
        for (int i = 0; i < k; ++i) {
            qualitySum += ratio[i].second;
            maxHeap.push(ratio[i].second);
        }

        double res = ratio[k-1] * qualitySum;
        for (int i = k; i < n; ++i) {
           
            maxHeap.push(ratio[i].second);
            
            qualitySum += ratio[i].second - maxHeap.top(); 
            maxHeap.pop();
            
            res = min(res, qualitySum * ratio[i].first);
        }

        return res;
    }
};