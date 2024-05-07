#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


/*
Runtime
7
ms
Beats
83.79%
of users with C++
Memory
17.01
MB
Beats
87.46%
of users with C++
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;
        
        Node* leftmost = root;

        while(leftmost){
            Node* curr = leftmost;
            Node* prev = nullptr;
            leftmost = nullptr;

            while(curr){
                
                if(curr->left){
                    if(!leftmost)
                        leftmost = curr->left;

                    if(prev)
                        prev->next = curr->left;

                    prev = curr->left;
                }

                if(curr->right){
                    if(!leftmost)
                        leftmost = curr->right;

                    if(prev)
                        prev->next = curr->right;

                    prev = curr->right;
                }

                curr = curr->next;
            }
        }

        return root;
    }
};




/*
Runtime
22
ms
Beats
8.57%
of users with C++
Memory
17.08
MB
Beats
87.46%
of users with C++
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) 
            return nullptr;
        helper(root);
        return root;
    }

    void helper(Node* root){
        if(!root) 
            return;

        if(root->left && root->right){
            root->left->next = root->right;
        }

        helper(root->left);
        helper(root->right);
        helper2(root->left, root->right);
    }

    void helper2(Node* leftNode, Node* rightNode){
        if(!leftNode || !rightNode) return;
        if(!leftNode->next)
            leftNode->next = rightNode;

        helper2(leftNode->right, rightNode->left);
        helper2(leftNode->right, rightNode->right);
        helper2(leftNode->left, rightNode->left);
        helper2(leftNode->left, rightNode->right);
    }
};








/*
Runtime
7
ms
Beats
83.79%
of users with C++
Memory
17.58
MB
Beats
18.60%
of users with C++
*/
// BFS, with exta space, 2x que
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) 
            return root;

        int q = 0;
        int nq = 1;
        vector<queue<Node*>> ques(2, queue<Node*>());
        if(root->left)
            ques[0].push(root->left);
        if(root->right)
            ques[0].push(root->right);

        while(true){
            while(!ques[q].empty()){
                Node* node = ques[q].front(); ques[q].pop();
                
                if(!ques[q].empty()){
                    Node* nextNode = ques[q].front();
                    node->next = nextNode;
                }

                if(node->left)
                    ques[nq].push(node->left);
                if(node->right)
                    ques[nq].push(node->right);
            }
            if(ques[q].empty() && ques[nq].empty()) break;
            swap(q, nq);
        }

        return root;
    }
};