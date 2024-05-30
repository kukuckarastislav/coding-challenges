#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>
using namespace std;


// DFS
/*
Runtime
11
ms
Beats
92.38%
of users with C++
Memory
17.61
MB
Beats
41.13%
of users with C++
*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n = prerequisites.size();
        
        if(n == 0) 
            return true;

        unordered_map<int, vector<int>> graphPrerequisites;
        for(int i = 0; i < n; i++){
            graphPrerequisites[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> state(numCourses, 0);
        for(int i = 0; i < n; i++){
            if(hasLoop(graphPrerequisites, state, prerequisites[i][1]))
                return false;
        }

        return true;
    }

    bool hasLoop(unordered_map<int, vector<int>>& graphPrerequisites, 
                vector<int>& state, int course)
    {
        if(state[course] == 1) return true;
        if(state[course] == 2) return false;

        state[course] = 1;

        for(int nextCourse : graphPrerequisites[course]){
            if(hasLoop(graphPrerequisites, state, nextCourse))
                return true;
        }

        state[course] = 2;
        return false;
    }
};


int main(){

    int numCourses = 5;
    vector<vector<int>> prerequisites({{1,4},{2,4},{3,1},{3,2}});
    Solution sol;
    bool cann = sol.canFinish(numCourses, prerequisites);

    return 0;
}


/*
Runtime
18
ms
Beats
44.66%
of users with C++
Memory
17.55
MB
Beats
47.31%
of users with C++
*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n = prerequisites.size();
        
        if(n == 0) 
            return true;

        unordered_map<int, vector<int>> graph;
        vector<int> indegree(numCourses, 0);

        for(int i = 0; i < n; i++){
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
            indegree[prerequisites[i][1]]++;
        }

        queue<int> que;
        vector<int> ans;

        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                que.push(i);
            }
        }

        while(!que.empty()){
            int currCourse = que.front(); que.pop();
            ans.push_back(currCourse);

            for(int nextCourse : graph[currCourse]){
                indegree[nextCourse]--;
                if(indegree[nextCourse] == 0){
                    que.push(nextCourse);
                }
            }
        }

        return ans.size() == numCourses;
    }
};





// BFS
/*
Runtime
478
ms
Beats
5.03%
of users with C++
Memory
182.56
MB
Beats
5.01%
of users with C++
*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n = prerequisites.size();
        
        if(n == 0) 
            return true;

        unordered_map<int, vector<int>> graphPrerequisites;
        for(int i = 0; i < n; i++){
            graphPrerequisites[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        unordered_set<int> coursesTestForLoops;
        for(int i = 0; i < n; i++){
            if(coursesTestForLoops.count(prerequisites[i][1]))
                continue;
            if(hasLoop(graphPrerequisites, prerequisites[i][1]))
                return false;
            coursesTestForLoops.insert(prerequisites[i][1]);
        }

        return true;
    }

    bool hasLoop(unordered_map<int, vector<int>>& graphPrerequisites, int startingCourse){
        unordered_set<int> visited;
        queue<int> que;

        que.push(startingCourse);
    
        while(!que.empty()){
            int currCourse = que.front(); que.pop();

            for(int nextCourse : graphPrerequisites[currCourse]){
                if(nextCourse == startingCourse)
                    return true;

                if(!visited.count(nextCourse)){
                    que.push(nextCourse);
                    visited.insert(nextCourse);
                }
            }

        }

        return false;
    }
};
