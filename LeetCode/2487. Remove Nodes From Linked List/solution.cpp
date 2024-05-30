#include <stack>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



/*
Runtime
243
ms
Beats
95.28%
of users with C++
Memory
164.53
MB
Beats
57.95%
of users with C++
*/
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if(!head->next)
            return head;

        ListNode* node = removeNodes(head->next);
        if(head->val < node->val)
            return node;
        
        head->next = node;
        return head;
    }
};






/*
Runtime
255
ms
Beats
85.46%
of users with C++
Memory
170.52
MB
Beats
30.30%
of users with C++
*/
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {

        vector<ListNode*> stk; 
        ListNode* it = head;

        while(it){
            while(!stk.empty() && it->val > stk.back()->val)
                stk.pop_back();
            
            stk.push_back(it);
            it = it->next;
        }

        int n = stk.size();
        for(int i = 0; i < n-1; i++){
            stk[i]->next = stk[i+1];
        }

        return stk[0];
    }
};








/*
Runtime
275
ms
Beats
55.54%
of users with C++
Memory
167.10
MB
Beats
44.60%
of users with C++
*/
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {

        stack<ListNode*> stk; // Monotonic Stack
        ListNode* it = head;

        while(it){
            while(!stk.empty() && it->val > stk.top()->val)
                stk.pop();
            
            stk.push(it);
            it = it->next;
        }

        ListNode* next = stk.top(); stk.pop();
        next->next = nullptr;
        while(!stk.empty()){
            it = stk.top(); stk.pop();
            it->next = next;
            next = it;
        }

        return next;
    }
};



/*
Time Limit Exceeded
*/
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        
        ListNode* it = head;
        ListNode* prev = nullptr;
        
        bool repeat = true;
        while(repeat){

            it = head;
            prev = nullptr;
            repeat = false;
            while(it && it->next){
                
                if(it->val < it->next->val){
                    if(!prev)
                        head = it->next;
                    else
                        prev->next = it->next;

                    repeat = true;
                    break;
                }
                
                prev = it;
                it = it->next;
            }
        }
       
        return head;
    }
};

