
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


/*
Runtime
156
ms
Beats
93.46%
of users with C++
Memory
120.87
MB
Beats
65.02%
of users with C++
*/
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        head = _doubleIt(head);
        if(head->val >= 10){
            head->val -= 10;
            head = new ListNode(1, head);
        }
        
        return head;
    }

private:
    ListNode* _doubleIt(ListNode* head) {
        
        head->val *= 2;
        if(!head->next)
            return head;
        
        ListNode* next = _doubleIt(head->next);
        if(next->val >= 10){
            next->val -= 10;
            head->val += 1;
        }

        return head;
    }
};