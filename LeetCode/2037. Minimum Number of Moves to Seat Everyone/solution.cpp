#include <vector>
#include <algorithm>
using namespace std;


/*
Runtime
3
ms
Beats
91.43%
Memory
20.93
MB
Beats
52.06%
*/
class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int n = seats.size();
        int moves = 0;

        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        for(int i = 0; i < n; i++){
            moves += abs(seats[i] - students[i]);
        }

        return moves;
    }
};