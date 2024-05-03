#include <string>
#include <vector>
using namespace std;



/*
Runtime
0
ms
Beats
100.00%
of users with C++
Memory
7.55
MB
Beats
36.10%
of users with C++
*/
class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1; 
        versionToVector(v1, version1);
        vector<int> v2;
        versionToVector(v2, version2);

        
        int n = min(v1.size(), v2.size());

        for(int i = 0; i < n; i++){
            if(v1[i] < v2[i]){
                return -1;
            }else if(v1[i] > v2[i]){
                return 1;
            }
        }

        if(v1.size() < v2.size()) 
            return -1;
        else if(v1.size() > v2.size()) 
            return 1;
        
        return 0;
    }

    void versionToVector(vector<int>& v, const string& version){
        int n = version.size();
        int num = 0;
        for(int i = 0; i < n; i++){
            if(version[i] == '.'){
                v.push_back(num);
                num = 0;
            }else if(version[i] >= '0' && version[i] <= '9'){
                num = num*10 + (version[i]-'0');
            }
        }
        v.push_back(num);
        while(v.size() > 1 && v.back() == 0) 
            v.pop_back();
    }
};