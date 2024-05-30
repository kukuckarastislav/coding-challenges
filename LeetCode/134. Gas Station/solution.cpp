class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for(int i = 0; i < n; i++){
            int tank = 0;
            if(gas[i] >= cost[i]){
                //cout << "Starting at gas station " << i << endl;
                int j;
                for(j = i; j < n+i; j++){
                    int k = j;
                    if(j >= n) k = j - n;
                    tank += gas[k] - cost[k];
                    //cout << "Tank " << tank << endl;
                    if(tank < 0) break;
                }
                if(tank >= 0) return i;
                else i = j;
            }
        }

        return -1;
    }
};