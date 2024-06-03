#include <vector>
#include <queue>
using namespace std;



/*
Runtime
164
ms
Beats
25.45%
of users with C++
Memory
87.86
MB
Beats
16.22%
of users with C++
*/
struct Project{
    int profit;
    int capital;
    Project(int _profit, int _capital){
        profit = _profit;
        capital = _capital;
    }
};

struct CompareForMaxHeap{
    bool operator()(const Project& p1, const Project& p2){
        return p1.profit < p2.profit;
    }
};

struct compareForMinHeap{
    bool operator()(const Project& p1, const Project& p2){
        return p1.capital > p2.capital;
    }
};

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
    
        priority_queue<Project, vector<Project>, CompareForMaxHeap> maxProfitProjectHeap;
        priority_queue<Project, vector<Project>, compareForMinHeap> minCapitaltProjectHeap;

        for(int i = 0; i < n; i++){
            minCapitaltProjectHeap.push(Project{profits[i], capital[i]});
        }

        for(int i = 0; i < k; i++){

            while(minCapitaltProjectHeap.size() && w >= minCapitaltProjectHeap.top().capital){
                maxProfitProjectHeap.push(minCapitaltProjectHeap.top());
                minCapitaltProjectHeap.pop();
            }

            if(maxProfitProjectHeap.empty())
                break;

            w += maxProfitProjectHeap.top().profit;
            maxProfitProjectHeap.pop();
        }
      
        return w;
    }
};




int main(){

    int k = 2;
    int w = 0;
    vector<int> profits = {1,2,3};
    vector<int> capital = {0,1,1};

    Solution sol;
    int profit = sol.findMaximizedCapital(k, w, profits, capital);

    return 0;
}
