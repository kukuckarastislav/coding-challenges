#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;



/*
Runtime
0
ms
Beats
100.00%
of users with C++
Memory
9.80
MB
Beats
66.67%
of users with C++
*/
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n2 = arr2.size();

        int arr2MapIdx[1001];
        fill(arr2MapIdx, end(arr2MapIdx), n2);

        for(int i = 0; i < n2; i++)
            arr2MapIdx[arr2[i]] = i;

        sort(arr1.begin(), arr1.end(), [&](int x, int y){
            if(arr2MapIdx[x] == arr2MapIdx[y]) 
                return x < y;
            
            return arr2MapIdx[x] < arr2MapIdx[y];
        });

        return arr1;
    }   
};







/*
Runtime
0
ms
Beats
100.00%
of users with C++
Memory
10.37
MB
Beats
13.68%
of users with C++
*/
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res;

        unordered_map<int, int> mp;
        for(int x : arr1) 
            mp[x]++;

        for(int x : arr2){
            for(int i = 0; i < mp[x]; i++)
                res.push_back(x);
            
            mp[x] = 0;
        }

        int offset = res.size();

        for(int x : arr1)
            if(mp[x])
                res.push_back(x);
            
        sort(res.begin() + offset, res.end());

        return res;
    }   
};