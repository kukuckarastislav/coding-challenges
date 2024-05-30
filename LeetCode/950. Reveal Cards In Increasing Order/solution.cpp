class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int> res(n, 0);

        sort(deck.begin(), deck.end());

        int i = 0;
        int j = 0;

        bool skip = false;

        while(i < n){

            if(res[j] == 0){
                if(!skip){
                    res[j] = deck[i];
                    i++;
                }

                skip = !skip;
            }

            j = (j+1) % n;
        }

        return res;
    }
};