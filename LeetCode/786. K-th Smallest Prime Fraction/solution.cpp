#include <vector>
#include <algorithm>
using namespace std;

/*
Runtime
3
ms
Beats
96.73%
of users with C++
Memory
10.62
MB
Beats
92.50%
of users with C++
*/
// binary search
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        
        int n = arr.size();
        
        double left = 0;
        double right = 1;
        double mid;

        while(left < right){
            mid = left + (right - left)/2;

            auto [count, arrI, arrJ] = countOfSmallerOrEqualElements(arr, mid);

            if(count < k)
                left = mid;
            else if(count > k)
                right = mid;
            else
                return {arrI, arrJ};
        }
        
        return {-1,-1};
    }

private:
    tuple<int, int, int> countOfSmallerOrEqualElements(vector<int>& arr, double target){
        int n = arr.size();

        int count = 0;
        int i = 0;
        int j = 1;

        int arrI, arrJ;
        double maxFraction = 0;

        while(i < n - 1){
            while(j < n && arr[i] > target * arr[j]) 
                j++;
            
            count += (n-j);

            if(n == j) 
                break;

            double currFraction = (double)arr[i]/arr[j];
            if(currFraction > maxFraction){
                maxFraction = currFraction;
                arrI = arr[i];
                arrJ = arr[j];
            }

            i++;
        }

        return {count, arrI, arrJ};
    }
};






/*
Runtime
285
ms
Beats
61.51%
of users with C++
Memory
120.64
MB
Beats
28.63%
of users with C++
*/
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        vector<pair<double, pair<int, int>>> primeFactors;

        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                primeFactors.push_back({(double)arr[i]/arr[j], {arr[i], arr[j]}});
            }
        }

        sort(primeFactors.begin(), primeFactors.end(), 
            [](const pair<double, pair<int, int>>& a, const pair<double, pair<int, int>>& b){
                return a.first < b.first;
            }
        );

        vector<int> ans(2, 0);
        ans[0] = primeFactors[k-1].second.first;
        ans[1] = primeFactors[k-1].second.second;
        return ans;
    }
};