#include <vector>
#include <algorithm>
using namespace std;



/*
Runtime
240
ms
Beats
84.58%
of users with C++
Memory
93.14
MB
Beats
86.82%
of users with C++
*/
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });
        int arrows = 0;

        int i = 0;
        int j;
        while(i < n){
            j = i+1;
            while(j < n && points[i][1] >= points[j][0]){
                j++;
            }
            i = j;
            arrows++;
        }
        
        return arrows;
    }
};






class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b){
            if(a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0];
        });
        int arrows = 0;

        int i = 0;
        int j;
        while(i < n){
            j = i+1;
            while(j < n && isOverlapping(points[i], points[j])){
                j++;
            }
            i = j;
            arrows++;
        }
        
        return arrows;
    }

    bool isOverlapping(const vector<int>& p1, const vector<int>& p2){
        return !(p1[1] < p2[0] || p2[1] < p1[0]);
    }
};




/*
python code to visual problem

l = [[9,12],[1,10],[4,11],[8,12],[3,9],[6,9],[6,7]]

for i in l:
    print(' '*i[0]+'_'*i[1])
print("0")
l.sort()
for i in l:
    print(' '*i[0]+'_'*i[1])
*/