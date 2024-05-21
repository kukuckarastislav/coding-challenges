#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>
using namespace std;





/*
Runtime
7
ms
Beats
98.98%
of users with C++
Memory
17.69
MB
Beats
42.33%
of users with C++
*/
/*
    BFS
    Topological sort
    (Topological sort. It refers to an order of vertices in which for every edge 
    u ➔ v, u comes before v in the ordering.)
*/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<int> coursesOrder;

        vector<int> numbOfPrerequisit(numCourses, 0);
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++){
            mp[prerequisites[i][1]].push_back(prerequisites[i][0]);
            numbOfPrerequisit[prerequisites[i][0]]++;
        }

        queue<int> queCourses;
        for(int i = 0; i < numCourses; i++){
            if(numbOfPrerequisit[i] == 0)
                queCourses.push(i);
        }

        while(!queCourses.empty()){
            int currCourse = queCourses.front(); queCourses.pop();
            coursesOrder.push_back(currCourse);

            for(int nextCourse : mp[currCourse]){
                numbOfPrerequisit[nextCourse]--;
                if(numbOfPrerequisit[nextCourse] == 0)
                    queCourses.push(nextCourse);
            }

        }

        if(coursesOrder.size() != numCourses) 
            return {};
        
        return coursesOrder;
    }
};




/*
Runtime
13
ms
Beats
78.30%
of users with C++
Memory
17.90
MB
Beats
30.79%
of users with C++
*/
/*
    DFS
    Topological sort
    (Topological sort. It refers to an order of vertices in which for every edge 
    u ➔ v, u comes before v in the ordering.)
*/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<int> coursesOrder;

        vector<int> numbOfPrerequisit(numCourses, 0);
        unordered_map<int, vector<int>> graph;

        for(int i = 0; i < n; i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            numbOfPrerequisit[prerequisites[i][0]]++;
        }

        for(int i = 0; i < numCourses; i++){
            if(numbOfPrerequisit[i] == 0){
                dfs(graph, numbOfPrerequisit, coursesOrder, i);
            }
        }

        if(coursesOrder.size() != numCourses) 
            return {};
        
        return coursesOrder;
    }

    void dfs(unordered_map<int, vector<int>>& graph, 
             vector<int>& numbOfPrerequisit, 
             vector<int>& coursesOrder, int currCourse)
    {
        coursesOrder.push_back(currCourse);
        numbOfPrerequisit[currCourse] = -1;
        for(int nextCourse : graph[currCourse]){
            numbOfPrerequisit[nextCourse]--;
            if(numbOfPrerequisit[nextCourse] == 0)
                dfs(graph, numbOfPrerequisit, coursesOrder, nextCourse);
        }
    }
};







/*
Runtime
17
ms
Beats
47.78%
of users with C++
Memory
17.70
MB
Beats
35.56%
of users with C++
*/
/*
    the algorithm uses the topological sort but in the opposite direction, 
    so in the end we have to do the reverse
*/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();

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

        if(ans.size() == numCourses){
            reverse(ans.begin(), ans.end());
            return ans;
        }

        return {};
    }
};





/*
Runtime
55
ms
Beats
5.19%
of users with C++
Memory
23.30
MB
Beats
5.05%
of users with C++
*/
/*
    the algorithm does not take advantage of the topological sort
    this is the reason why we have to check some courses more than once
*/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<int> coursesOrder;

        vector<int> numbOfPrerequisit(numCourses, 0);
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++){
            mp[prerequisites[i][0]].push_back(prerequisites[i][1]);
            numbOfPrerequisit[prerequisites[i][0]]++;
        }

        queue<int> queCourses;
        for(int i = 0; i < numCourses; i++){
            if(numbOfPrerequisit[i] == 0){
                coursesOrder.push_back(i);
            }else{
                queCourses.push(i);
            }
        }


        int numOfNewCoursesPassed = 1;
        while(!queCourses.empty() && numOfNewCoursesPassed){
            numOfNewCoursesPassed = 0;

            int queSize = queCourses.size();
            while(queSize--){
                int currCourse = queCourses.front(); queCourses.pop();
                
                int numOfPassedPreqC = 0;
                for(int prerC : mp[currCourse]){
                    if(numbOfPrerequisit[prerC] == 0)
                        numOfPassedPreqC++;
                }
                if(numOfPassedPreqC == numbOfPrerequisit[currCourse]){
                    coursesOrder.push_back(currCourse);
                    numbOfPrerequisit[currCourse] = 0;
                    numOfNewCoursesPassed++;
                }else{
                    queCourses.push(currCourse);
                }
            }
        }


        if(coursesOrder.size() != numCourses) 
            return {};
        
        return coursesOrder;
    }
};






/*
Runtime
71
ms
Beats
5.19%
of users with C++
Memory
17.81
MB
Beats
32.51%
of users with C++
*/
/*
    without que

    the algorithm does not take advantage of the topological sort
    this is the reason why we have to check some courses more than once
*/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<int> coursesOrder;

        vector<int> numbOfPrerequisit(numCourses, 0);
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++){
            mp[prerequisites[i][0]].push_back(prerequisites[i][1]);
            numbOfPrerequisit[prerequisites[i][0]]++;
        }

        unordered_set<int> passedCourses;
        for(int i = 0; i < numCourses; i++){
            if(numbOfPrerequisit[i] == 0){
                coursesOrder.push_back(i);
                passedCourses.insert(i);
                numbOfPrerequisit[i] = -1;
            }
        }

        for(int i = 0; i < numCourses; i++){
            if(numbOfPrerequisit[i] > 0){
                int passedPre = 0;
                for(int pre : mp[i]){
                    if(passedCourses.count(pre))
                        passedPre++;
                }
                if(passedPre == numbOfPrerequisit[i]){
                    numbOfPrerequisit[i] = -1;
                    passedCourses.insert(i);
                    coursesOrder.push_back(i);
                    i = -1;
                }
            }
        }

        if(coursesOrder.size() != numCourses) 
            return {};
        
        return coursesOrder;
    }
};