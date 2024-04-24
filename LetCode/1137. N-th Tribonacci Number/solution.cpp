class Solution {
public:
    int tribonacci(int n) {
        if(n <= 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 1;

        int t0 = 0;
        int t1 = 1;
        int t2 = 1;
        int t3;

        int sum = 0;
        for(int i = 2; i < n; i++){
            t3 = t0 + t1 + t2;
            t0 = t1;
            t1 = t2;
            t2 = t3;
        }

        return t3;
    }
};