
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


/*
Runtime
3
ms
Beats
99.12%
of users with C++
Memory
10.51
MB
Beats
61.34%
of users with C++
*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr) 
            return false;

        ListNode* slow = head;
        ListNode* fast = head;

        while(slow != nullptr && fast != nullptr && fast->next != nullptr){
            if(fast->val == __INT_MAX__)
                return true;
            slow->val = __INT_MAX__;
            slow = slow->next;
            fast = fast->next->next;
        }

        return false;
    }
};



/*
Runtime
3
ms
Beats
99.12%
of users with C++
Memory
10.56
MB
Beats
61.34%
of users with C++
*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr) 
            return false;

        ListNode* slow = head;
        ListNode* fast = head;

        while(slow != nullptr && fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                return true;
        }

        return false;
    }
};
