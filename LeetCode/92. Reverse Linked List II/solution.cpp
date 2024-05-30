
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
Runtime
0
ms
Beats
100.00%
of users with C++
Memory
9.28
MB
Beats
89.21%
of users with C++
*/

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(!head->next || left == right) 
            return head;

        ListNode* it = head;
        int i = 1;

        ListNode* itBefLeft = nullptr;
        ListNode* itLeft = head;

        if(left > 1){
            i++;
            itBefLeft = head;
            while(itBefLeft && i < left){
                itBefLeft = itBefLeft->next;
                i++;
            }
            itLeft = itBefLeft->next;
        }

        ListNode* prev = itLeft;
        it = itLeft->next;
        i++;
        while(it){
            
            ListNode* next = it->next;
            ListNode* tempPrev = prev;
            prev = it;
            it->next = tempPrev;
            
            if(i == right){
                itLeft->next = next;
                if(left == 1) head = it;
                else itBefLeft->next = it;
                break;
            }

            it = next;
            i++;
        }

        return head;
    }
};