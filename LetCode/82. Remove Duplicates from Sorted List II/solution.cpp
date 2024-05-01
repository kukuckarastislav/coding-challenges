
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
89.03%
of users with C++
Memory
14.01
MB
Beats
71.90%
of users with C++
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(!head) 
            return nullptr;

        ListNode* it = head;
        ListNode* prev = head;

        do{
            prev = head;
            while(it && it->next && it->val == it->next->val){
                it = it->next;
                head = it->next;
            }
        it = it->next;
        }while(it && prev != head);

        while(it && it->next){
            
            if(it->val == it->next->val){
                while(it && it->next && it->val == it->next->val){
                    it = it->next;
                }
                prev->next = it->next;
            }else{
                prev = it;
            }
            
            it = it->next;
        }

        return head;
    }
};