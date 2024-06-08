#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stdlib.h>
using namespace std;



/*
Runtime
14
ms
Beats
95.72%
of users with C++
Memory
15.12
MB
Beats
67.92%
of users with C++
*/
/*
    Time: O(n*n)
    Space: O(n)
*/
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 1)
            return 1;

        unordered_map<double, int> slopes;

        int maxColl = 0;
        for(int i = 0; i < n-1; i++){
            slopes.clear();
            int currColl = 0;
            
            for(int j = i+1; j < n; j++){
                double slope = getSlope(points[i][0], points[i][1], points[j][0], points[j][1]);
                slopes[slope] += 1;
                currColl = max(currColl, slopes[slope]);
            }

            maxColl = max(maxColl, currColl);
        }

        return maxColl+1;
    }

private:
    double getSlope(int x1, int y1, int x2, int y2){
        if(x1 == x2) return INT_MAX;
        return (double)(y1 - y2) / (double)(x1 - x2);
    }
};




int main(){

    vector<vector<int>> points = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    Solution sol;
    int x = sol.maxPoints(points);

    return 0;
}



/*
Runtime
115
ms
Beats
11.00%
of users with C++
Memory
9.06
MB
Beats
86.52%
of users with C++
*/
/*
    Time: O(n*n*n)
    Space: O(1)
*/
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 1)
            return 1;

        int maxColl = 0;
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){

                int currColl = 2;
                for(int k = 0; k < n; k++){
                    if(k == i or k == j) continue;

                    if(isCollinear(
                        points[i][0], points[i][1], 
                        points[j][0], points[j][1], 
                        points[k][0], points[k][1]))
                    {
                        currColl++;
                    }
                }

                maxColl = max(maxColl, currColl);
            }
        }

        return maxColl;
    }

private:
    bool isCollinear(int x1, int y1, int x2, int y2, int x3, int y3){
        return (y1 - y2) * (x1 - x3) == (y1 - y3) * (x1 - x2);
    }

};



/*
Runtime
167
ms
Beats
5.07%
of users with C++
Memory
26.08
MB
Beats
12.06%
of users with C++
*/
// need FIX memo
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 1)
            return 1;

        int maxColl = 0;
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                
                double a = abs( getSlope(points[i][0], points[i][1], points[j][0], points[j][1]) );
                double b = getB(points[i][0], points[i][1], points[j][0], points[j][1]);
                
                if(isLineVisited(a,b))
                    continue;

                int currColl = 2;
                for(int k = 0; k < n; k++){
                    if(k == i or k == j) continue;

                    if(isCollinear(
                        points[i][0], points[i][1], 
                        points[j][0], points[j][1], 
                        points[k][0], points[k][1]))
                    {
                        currColl++;
                    }
                }

                maxColl = max(maxColl, currColl);
                visitedLines[a].insert(b);
            }
        }

        return maxColl;
    }

private:
    // y=ax+b          a, b
    unordered_map<double, unordered_set<double>> visitedLines;

    bool isCollinear(int x1, int y1, int x2, int y2, int x3, int y3){
        return (y1 - y2) * (x1 - x3) == (y1 - y3) * (x1 - x2);
    }

    double getSlope(int x1, int y1, int x2, int y2){
        if(x1 == x2) return INT_MAX;
        return (double)(y1 - y2) / (double)(x1 - x2);
    }

    bool isLineVisited(double a, double b){
        auto slopeMemo = visitedLines.find(a);
        if(slopeMemo != visitedLines.end() && slopeMemo->second.count(b))
            return true;

        return false;
    }

    double getB(int x1, int y1, int x2, int y2){
        return (x2 * y1 - x1 * y2) / (double)(x2 - x1);
    }
};