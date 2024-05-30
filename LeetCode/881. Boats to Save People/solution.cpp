#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(people.begin(), people.end());
        
        int n = people.size();
        int boats = 0;

        int i = 0;
        int j = n-1;

        while(i <= j){

            if(people[i] + people[j] <= limit)
                i++;

            j--;
            boats++;
        }

        return boats;
    }
};