#include <vector>
using namespace std;



class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

/*
Runtime
4
ms
Beats
93.01%
of users with C++
Memory
17.26
MB
Beats
85.66%
of users with C++
*/
class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return constructQuadTree(grid, grid.size(), 0, 0);
    }

    Node* constructQuadTree(vector<vector<int>>& grid, int n, int iStart, int jStart){
        Node* head = new Node(true, false);

        if(isMatrixWithAllSameElements(grid, n, iStart, jStart)){
            head->isLeaf = true;
            head->val = grid[iStart][jStart];
            return head;
        }

        int mid = n/2;
        head->topLeft = constructQuadTree(grid, mid, iStart, jStart);
        head->topRight = constructQuadTree(grid, mid, iStart, mid+jStart);
        head->bottomLeft = constructQuadTree(grid, mid, mid+iStart, jStart);
        head->bottomRight = constructQuadTree(grid, mid, mid+iStart, mid+jStart);

        return head;
    }

    bool isMatrixWithAllSameElements(vector<vector<int>>& grid, int n, int iStart, int jStart){
        int firstVal = grid[iStart][jStart];
        for(int i = iStart; i < iStart+n; i++){
            for(int j = jStart; j < jStart+n; j++){
                if(firstVal != grid[i][j]){
                    return false;
                }
            }
        }

        return true;
    }
};