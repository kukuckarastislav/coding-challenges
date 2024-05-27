#include <vector>
using namespace std;



/*
Runtime
110
ms
Beats
52.72%
of users with C++
Memory
81.50
MB
Beats
56.32%
of users with C++
*/
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        backtrack(n, k, 1);
        return allCombinations;
    }

private:
    void backtrack(int n, int k, int i){
        if(k == combination.size()){
            allCombinations.push_back(combination);
            return;
        }

        for(int x = i; x <= n; x++){
            combination.push_back(x);
            backtrack(n, k, x+1);
            combination.pop_back();
        }
    }

    vector<vector<int>> allCombinations;
    vector<int> combination;
};




/*
Runtime
136
ms
Beats
29.88%
of users with C++
Memory
129.02
MB
Beats
21.73%
of users with C++
*/
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        backtrack(n, k, 0);
        return allCombinations;
    }

private:
    void backtrack(int n, int k, int i){
        if(k == combination.size()){
            allCombinations.push_back(combination);
            return;
        }

        if(i == n)
            return;

        // exclude
        backtrack(n, k, i+1);

        // include
        combination.push_back(i+1);
        backtrack(n, k, i+1);
        combination.pop_back();
    }

    vector<vector<int>> allCombinations;
    vector<int> combination;
};