#include <vector>
#include <string>
#include <queue>
#include <bitset>
using namespace std;

/*
Runtime
8
ms
Beats
99.61%
of users with C++
Memory
13.67
MB
Beats
99.61%
of users with C++
*/

class Solution {
public:
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

        queue<pair<short, short>> que;
        que.emplace(0, 0);
        visited[0] = 1;
        short dec[4] = {1,10,100,1000};

        while(!que.empty()){
            auto [currDistance, currState] = que.front();
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
                        que.emplace(currDistance + 1, nextState);
                        visited[nextState] = 1;
                    }
                }
            }
        }

        return -1;
    }
};