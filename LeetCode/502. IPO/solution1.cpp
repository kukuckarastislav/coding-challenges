#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


/*
Runtime
125
ms
Beats
93.44%
of users with C++
Memory
85.42
MB
Beats
63.96%
of users with C++
*/
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        
        vector<pair<int, int>> projects;
        for(int i = 0; i < n; i++){
            projects.push_back({capital[i], profits[i]});
        }
        sort(projects.begin(), projects.end());

        priority_queue<int> maxHeap;

        int i = 0;
        while(k){
            while(i < n && w >= projects[i].first){
                maxHeap.push(projects[i].second);
                i++;
            }

            if(maxHeap.empty())
                break;

            w += maxHeap.top(); maxHeap.pop();
            k--;
        }
        
        return w;
    }
};
