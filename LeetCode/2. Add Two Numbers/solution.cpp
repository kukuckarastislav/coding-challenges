struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


/*
Runtime
11
ms
Beats
96.27%
of users with C++
Memory
75.40
MB
Beats
97.82%
of users with C++
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* _l1 = l1;
        ListNode* retList = l2;
        ListNode* it = nullptr;

        int carry = 0;
        int currVal = 0;
        while(l1 != nullptr && l2 != nullptr){
            currVal = l1->val + l2->val + carry;
            if(currVal > 9){
                currVal = currVal - 10;
                carry = 1;
            }else{
                carry = 0;
            }
            l1->val = currVal;
            l2->val = currVal;

            it = l2;
            l1 = l1->next;
            l2 = l2->next;
        }

        if(l1 != nullptr){
            retList = _l1;
        }
        while(l1 != nullptr && carry){
            currVal = l1->val + carry;
            if(currVal > 9){
                currVal = currVal - 10;
                carry = 1;
            }else{
                carry = 0;
            }
            l1->val = currVal;
            it = l1;
            l1 = l1->next;
        }

        while(l2 != nullptr && carry){
            currVal = l2->val + carry;
            if(currVal > 9){
                currVal = currVal - 10;
                carry = 1;
            }else{
                carry = 0;
            }
            l2->val = currVal;
            it = l2;
            l2 = l2->next;
        }

        if(carry){
            it->next = new ListNode(1);
        }
           
        return retList;
    }
};