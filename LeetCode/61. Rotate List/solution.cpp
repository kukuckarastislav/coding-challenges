
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
83.48%
of users with C++
Memory
15.07
MB
Beats
94.51%
of users with C++
*/
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        int n = length(head);
        if(n == 0 || n == 1 || n == k || k == 0)
            return head;

        if(k > n) 
            k = k % n;
        
        if(k == 0) 
            return head;

        ListNode* it = head;
        for(int i = 0; i < (n-k-1); i++){
            it = it->next;
        }

        ListNode* first = head;
        head = it->next;
        it->next = nullptr;
        it = head;
        while(it && it->next){
            it = it->next;
        }
        it->next = first;

        return head;
    }

    int length(ListNode* head){
        int n = 0;
        ListNode* it = head;
        while(it){
            it = it->next;
            n++;
        }
        return n;
    }
};