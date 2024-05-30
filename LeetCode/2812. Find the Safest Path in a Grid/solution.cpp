#include <vector>
#include <math.h>
#include <queue>
#include <stdlib.h>
using namespace std;

#include <iostream>
#include <chrono>

// BFS multisource + BFS + pque + Binary Search
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] || grid[n-1][n-1]) 
            return 0;

        distToNearestThief.resize(n, vector<int>(n, 0));
        int maxDist = findAllDistToNearestThiefAndReturnMaxDist(grid);

        int ans = 0;

        int low = 0;
        int high = maxDist;
        int mid = 0;

        while(low <= high){
            
            int mid = (low+high)/2;
            
            if(isSafe(grid, mid)){
                ans = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        return ans;
    }

private:
    vector<vector<int>> distToNearestThief;

    int dx[4] = {1, 0,-1, 0};
    int dy[4] = {0, 1, 0,-1};

    int findAllDistToNearestThiefAndReturnMaxDist(vector<vector<int>>& grid){
        int n = grid.size();
        queue<pair<int, int>> que;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    que.push({i, j});
                }
            }
        }

        int dist = -1;
        while(!que.empty()){
            int queSize = que.size();
            dist++;
            while(queSize--){
                int i = que.front().first;
                int j = que.front().second;
                que.pop();

                if(visited[i][j])
                    continue;

                visited[i][j] = true;
                distToNearestThief[i][j] = dist;
                
                for(int d = 0; d < 4; d++){
                    int ii = i + dx[d];
                    int jj = j + dy[d];
                    if(!isValid(grid, visited, ii, jj)) 
                        continue;
                    que.push({ii, jj});
                }
            }
        }

        return dist;
    }

    bool isSafe(vector<vector<int>>& grid, int safestFactor){
        int n = grid.size();

        if(distToNearestThief[0][0] < safestFactor) return false;

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        priority_queue<pair<int ,pair<int, int>>> que;

        que.push({distToNearestThief[0][0], {0, 0}});
        visited[0][0] = true;

        while(!que.empty()){

            auto cell = que.top(); que.pop();

            int i = cell.second.first;
            int j = cell.second.second;

            if(i == n-1 && j == n-1)
                return true;

            for(int k = 0; k < 4; k++){
                int ii = i+dx[k];
                int jj = j+dy[k];
                if(!isValid(grid, visited, ii, jj) || distToNearestThief[ii][jj] < safestFactor)
                    continue;
                que.push({distToNearestThief[ii][jj], {ii, jj}});
                visited[ii][jj] = true;
            }

        }

        return false;
    }

    bool isValid(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid.size() || visited[i][j])
            return false;
        return true;
    }
};



int main(){

    vector<vector<int>> grid({
        {0,0,0,0,0,0,1},
        {0,0,0,1,0,0,0},
        {0,0,0,0,0,0,0},
        {1,0,0,0,0,0,0},
        {0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
    });

    Solution sol;    
    auto start = chrono::high_resolution_clock::now();
    int x = sol.maximumSafenessFactor(grid);
    auto end = chrono::high_resolution_clock::now();
    cout << "Result: " << x << endl; //20 

    // for input grid nxn, n=400;
    // 18.1759s  BFS priority_que
    // 16.2231s  BFS multisource 
    // 0.001684s BFS multisource binarySearch
    // 0.002221s BFS multisource binarySearch priority_que
    cout << (double)chrono::duration_cast<chrono::microseconds>(end-start).count()/1000000<< endl;

    return 0;
}