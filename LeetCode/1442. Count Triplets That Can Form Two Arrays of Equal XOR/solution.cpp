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
9.00
MB
Beats
86.43%
of users with C++
*/
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int count = 0; 

        for(int i = 0; i < n-1; i++){
            int xorRes = 0;
            for(int j = i; j < n; j++){
                xorRes ^= arr[j];
                if(xorRes == 0) 
                    count += (j - i);
            }

        }

        return count;
    }
};





// TLE
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int count = 0; 

        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                for(int k = j; k < n; k++){
                    if(xorArr(arr, i, j-1) == xorArr(arr, j, k)){
                        count++;
                    }
                }
            }
        }

        return count;
    }

    int xorArr(vector<int>& arr, int start, int end){
        int xorResult = 0;
        for(int i = start; i <= end; i++){
            xorResult ^= arr[i];
        }

        return xorResult;
    }
};