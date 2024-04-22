#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>
using namespace std;


/*
Runtime
223
ms
Beats
38.66%
of users with C++
Memory
59.34
MB
Beats
33.34%
of users with C++
*/

class Solution {
public:

    /*
    bool compareBySimilarity(const string& target, const string& a, const string& b) {
        
        int diff1 = 0;
        int diff2 = 0;

        for(int i = 0; i < 4; i++){
            int d1 = abs(target[i] - a[i]);
            int d2 = abs(target[i] - b[i]);

            if(d1 > 5) d1 = 10-d1;
            if(d2 > 5) d2 = 10-d2;

            diff1 += d1;
            diff2 += d2;
        }

        return diff1 < diff2;
    }
    */

    vector<string> getNextStates(string currLockState, 
        unordered_set<string>& deadendsSet, 
        const string& target,
        unordered_map<string, int>& distance){

        vector<string> nextStates;

        for(int i = 3; i >= 0; i--){
            string stringUp = currLockState;
            string stringDown = currLockState;
            
            stringUp[i]++;
            stringDown[i]--;

            if(stringUp[i] > '9')
                stringUp[i] = '0';
            if(stringDown[i] < '0')
                stringDown[i] = '9';

            if(!deadendsSet.count(stringUp) && !distance.count(stringUp)){
                nextStates.push_back(stringUp);
                distance[stringUp] = distance[currLockState] + 1;
            }
            if(!deadendsSet.count(stringDown) && !distance.count(stringDown)){
                nextStates.push_back(stringDown);
                distance[stringDown] = distance[currLockState] + 1;
            }
        }

        /*
        sort(nextStates.begin(), nextStates.end(), [&](const string& a, const string& b) {
            return compareBySimilarity(target, a, b);
        });
        */
        
        return nextStates;
    }

    int openLock(vector<string>& deadends, string target) {
        
        unordered_set<string> deadendsSet(deadends.begin(), deadends.end());
        string startLockState = "0000";
        
        if(target == startLockState) 
            return 0;

        if(deadendsSet.count(startLockState))
            return -1;

        queue<string> que;
        que.push(startLockState);

        unordered_map<string, int> distance;
        distance[startLockState] = 0;

        while(!que.empty()){
            string currLockState = que.front();
            
            if(target == currLockState)
                break; 

            que.pop();

            for(string nextState : getNextStates(currLockState, deadendsSet, target, distance)){
                que.push(nextState);
            }
        }

        return distance.count(target) ? distance[target] : -1;
    }
};