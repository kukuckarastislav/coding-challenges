#include <vector>
#include <string>
#include <queue>
#include <bitset>
using namespace std;

/*
Runtime
9
ms
Beats
99.61%
of users with C++
Memory
13.14
MB
Beats
100.00%
of users with C++
*/

class Solution {
public:

    struct mycmp {
        bool operator()(tuple<short, short, short> a, tuple<short, short, short> b)
        {   
            return get<0>(a)+get<2>(a) > get<0>(b)+get<2>(b);
        }
    };

    int openLock(vector<string>& deadends, string target) {
        
        bitset<10000> visited = 0;
        for(string& s: deadends){
            visited[stoi(s)] = 1;
        }
        
        short targetState = stoi(target);
        if(visited[0] || visited[targetState]) 
            return -1;
        
        if("0000" == target) 
            return 0;

        priority_queue<tuple<short, short, short>, vector<tuple<short, short, short>>, mycmp> que;
        que.emplace(0, 0, 0);
        visited[0] = 1;
        short dec[4] = {1,10,100,1000};

        while(!que.empty()){
            auto [currDistance, currState, h] = que.top();
            que.pop();

            if(currState == targetState){
                return currDistance;
            }

            short digit;
            short temp = currState;            
            for(short d = 0; d < 4; d++){
                digit = temp % 10;
                temp /= 10;
                for(short i = -1; i <= 1; i+=2){
                    short digitNext = digit + i;
                    
                    if(digitNext > 9) digitNext = 0;
                    else if(digitNext < 0) digitNext = 9;
                    
                    short nextState = currState + (digitNext - digit)*dec[d];

                    if(!visited[nextState]){
                        int heuristic = getHeuristic(nextState, targetState);
                        que.emplace(currDistance + 1, nextState, heuristic);
                        visited[nextState] = 1;
                    }
                }
            }
        }

        return -1;
    }


    short getHeuristic(short startState, short targetState) {
        
        short diff = 0;

        for(short i = 1; i <= 4; i++){
            short ds = startState % 10;
            startState /= 10;

            short dt = targetState % 10;
            targetState /= 10;

            short d = abs(dt - ds);

            if(d > 5) d = 10-d;

            diff += d;
        }

        return diff;
    }
    
};