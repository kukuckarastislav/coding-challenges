#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*
Runtime
0
ms
Beats
100.00%
of users with C++
Memory
8.05
MB
Beats
40.37%
of users with C++
*/
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int n = bank.size();

        if(n == 0) return -1;
        if(startGene == endGene) return 0;

        
        unordered_map<string, vector<string>> graphNextMutation;
        bank.push_back(startGene);
        for(int i = 0; i <= n; i++){    // i <= n; because we added startGene to bank
            for(int j = i+1; j <= n; j++){
                if(canMutate(bank[i], bank[j])){
                    graphNextMutation[bank[i]].push_back(bank[j]);
                    graphNextMutation[bank[j]].push_back(bank[i]);
                }
            }
        }
        bank.pop_back(); // removing startGene

        if(graphNextMutation[endGene].size() == 0)
            return -1;


        int numOfMutation = 0;
        queue<string> que;
        unordered_set<string> visitedMutations;

        que.push(startGene);
        visitedMutations.insert(startGene);

        while(que.size()){

            int qsize = que.size();
            while(qsize--){
                string& currGene = que.front(); que.pop();

                if(currGene == endGene)
                    return numOfMutation;

                for(string& nextMutation : graphNextMutation[currGene]){
                    if(!visitedMutations.count(nextMutation)){
                        que.push(nextMutation);
                        visitedMutations.insert(nextMutation);
                    }
                }
                
            }

            numOfMutation++;
        }

        return -1;
    }

    bool canMutate(const string& gen1, const string& gen2){
        int diff = 0;
        for(int i = 0; i < 8; i++){
            if(gen1[i] != gen2[i]){
                diff++;
            }
        }

        return diff == 1;
    }
};


int main(){

    string startGene = "AACCGGTT";
    string endGene = "AAACGGTA";
    vector<string> bank({"AACCGGTA","AACCGCTA","AAACGGTA"});

    Solution sol;
    int x = sol.minMutation(startGene, endGene, bank);

    return 0;
}