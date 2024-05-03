/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};




class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* it = head;
        ListNode* headST = new ListNode(0);
        ListNode* itST = headST;
        ListNode* headGTE = new ListNode(0);
        ListNode* itGTE = headGTE;

        while(it){
            if(it->val < x){
                itST->next = it;
                itST = itST->next;
            }else{
                itGTE->next = it;
                itGTE = itGTE->next;
            }

            it = it->next;
        }
    
        itST->next = headGTE->next;
        itGTE->next = nullptr;

        return headST->next;
    }
};




/*
1 4 3 2 5 2, x=3

1 2 2   +
4 3 5

1 2 2 4 3 5
*/

/*
2 1, x=2

1   +
2

1 2
*/

/*
1 4 3 0 2 5 2, x=3

1 0 2 2
4 3 5

1 0 2 2 4 3 5
*/



