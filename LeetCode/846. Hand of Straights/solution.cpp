#include <vector>
#include <algorithm>
using namespace std;



/*
Runtime
54
ms
Beats
73.73%
of users with C++
Memory
23.26
MB
Beats
97.35%
of users with C++
*/
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0)
            return false;

        sort(hand.begin(), hand.end());

        while(hand.size()){
            int count = 1;
            int lastSelected = hand[0];
            hand.erase(hand.begin());
            
            for(int i = 0; i < hand.size(); i++){
                if(count >= groupSize)
                    break;
                if(lastSelected + 1 == hand[i]){
                    count++;
                    lastSelected = hand[i];
                    hand.erase(hand.begin() + i);
                    i--;
                }
            }

            if(count < groupSize)
                return false;
        }
        
        return true;
    }
};



int main(){

    vector<int> hand = {1,2,3,6,2,3,4,7,8};
    int groupSize = 3;

    Solution sol;
    auto res = sol.isNStraightHand(hand, groupSize);


    return 0;
}