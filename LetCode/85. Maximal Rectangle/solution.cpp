/*
Runtime
22
ms
Beats
93.84%
of users with C++
Memory
16.80
MB
Beats
74.19%
of users with C++
*/
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int maxRect = 0;
        int currRect = 0;

        vector<int> heights(cols + 1, 0);

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(matrix[i][j] == '1'){
                    heights[j] += 1;
                }else{
                    heights[j] = 0;
                }
            }

            stack<int> s;
            for(int k = 0; k < cols+1; k++){
                while(!s.empty() && heights[k] < heights[s.top()]){
                    int height = heights[s.top()];
                    s.pop();
                    int width = s.empty() ? k : k - s.top() - 1;
                    int currRect = width * height;
                    if(currRect > maxRect)
                        maxRect = currRect;
                }

                s.push(k);
            }
        }



        return maxRect;
    }
};






// brute force solution with information about already explored rectangles
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int maxRect = 0;
        int currRect = 0;

        vector<tuple<int,int,int,int>> exploredRect;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){

                if(matrix[i][j] == '0')
                    continue;
                
                int k, l;
                for(k = i; k < rows; k++){
                    for(l = j; l < cols; l++){

                        if(isExplored(exploredRect, i,j, k,l))
                            continue;
                        
                        currRect = countOnes(matrix, i,j, k,l);
                        //cout << currRect << " " << i << " " << j << " " << k << " " << l << endl;
                        if(currRect != -1){
                            if(currRect > maxRect){
                                maxRect = currRect;
                            }
                            updateExploredRect(exploredRect, i,j, k,l);
                        }else{
                            break;
                        }
                    }
                }
            }
        }

        return maxRect;
    }

    static bool sortByFunc(tuple<int, int, int, int>& t1, tuple<int, int, int, int>& t2){
        int i1 = get<0>(t1);
        int j1 = get<1>(t1);
        int i2 = get<2>(t1);
        int j2 = get<3>(t1);

        int i3 = get<0>(t2);
        int j3 = get<1>(t2);
        int i4 = get<2>(t2);
        int j4 = get<3>(t2);

        int Area1 = (i2-i1+1)*(j2-j1+1);
        int Area2 = (i4-i3+1)*(j4-j3+1);
        return Area1 < Area2;
    }

    void updateExploredRect(vector<tuple<int,int,int,int>>& exploredRect, int i1, int j1, int i2, int j2){
        auto it = exploredRect.begin();
        while(it != exploredRect.end()){
            int i3 = get<0>(*it);
            int j3 = get<1>(*it);
            int i4 = get<2>(*it);
            int j4 = get<3>(*it);

            if(i1 <= i3 && j1 <= j3 && i2 >= i4 && j2 >= j4){
                it = exploredRect.erase(it);
            }else{
                it++;
            }
        }

        exploredRect.push_back(make_tuple(i1, j1, i2, j2)); //make_tuple(i1, j1, i2, j2)
        sort(exploredRect.begin(), exploredRect.end(), sortByFunc);

    }

    bool isExplored(vector<tuple<int,int,int,int>>& exploredRect, int i1, int j1, int i2, int j2){
        for(auto rect : exploredRect){
            int i3 = get<0>(rect);
            int j3 = get<1>(rect);
            int i4 = get<2>(rect);
            int j4 = get<3>(rect);

            if(i3 <= i1 && j3 <= j1 && i4 >= i2 && j4 >= j2){
                return true;
            }
        }

        return false;
    }

    int countOnes(vector<vector<char>>& matrix, int i1, int j1, int i2, int j2){
        int count = 0;
        for(int i = i1; i <= i2; i++){
            for(int j = j1; j <= j2; j++){
                if(matrix[i][j] == '1')
                    count++;
                else
                    return -1;
            }
        }
        return count;
    }
};