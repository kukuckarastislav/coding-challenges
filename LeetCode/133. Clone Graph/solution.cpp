#include <vector>
#include <queue>
using namespace std;


class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
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
10.77
MB
Beats
99.67%
of users with C++
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;

        vector<Node*> newNodes(101, nullptr);
        queue<Node*> que;

        Node* newNode = new Node(node->val);
        newNodes[node->val] = newNode;
        que.push(node);

        while(!que.empty()){
            Node* currNode = que.front(); que.pop();

            for(auto it = currNode->neighbors.begin(); it != currNode->neighbors.end(); it++){
                Node* nextNode = *it;
                if(newNodes[nextNode->val] == nullptr){
                    newNodes[nextNode->val] = new Node(nextNode->val);
                    que.push(nextNode);
                }

                newNodes[currNode->val]->neighbors.push_back(newNodes[nextNode->val]);
            }
        }
    
        return newNode;
    }
};

