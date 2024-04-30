
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


/*
Runtime
3
ms
Beats
63.64%
of users with C++
Memory
13.19
MB
Beats
92.57%
of users with C++
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next) return nullptr;

        ListNode* it = head;
        ListNode* itTarget = head;
        n++;
        while(it && n--){
            it = it->next;
        }
        
        if(!it && n){
            return head->next;
        }

        while(it){
            it = it->next;
            itTarget = itTarget->next;
        }

        itTarget->next = itTarget->next->next;

        return head;
    }
};