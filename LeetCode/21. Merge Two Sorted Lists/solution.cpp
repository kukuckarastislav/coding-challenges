
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
82.49%
of users with C++
Memory
18.16
MB
Beats
95.67%
of users with C++
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;

        ListNode* head;
        
        if(list1->val <= list2->val){
            head = list1;
            list1 = list1->next;
        }else{
            head = list2;
            list2 = list2->next;
        }

        ListNode* curr = head;

        while (list1 && list2){
            
            if(list1->val <= list2->val){
                curr->next = list1;
                list1 = list1->next;
            }else{
                curr->next = list2;
                list2 = list2->next;
            }

            curr = curr->next;
        }

        if(list1){
            curr->next = list1;
        }else{
            curr->next = list2;  
        }
        
        return head;
    }
};