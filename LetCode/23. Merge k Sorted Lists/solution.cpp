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
9
ms
Beats
94.16%
of users with C++
Memory
16.47
MB
Beats
98.97%
of users with C++
*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();

        if(k == 0) return nullptr;
        if(k == 1) return lists[0];
        
        return _mergeKLists(lists, 0, k-1);
    }

private:
    ListNode* _mergeKLists(vector<ListNode*>& lists, int start, int end){
        if(start == end)
            return lists[start];

        if(start + 1 == end)
            return merge2Lists(lists[start], lists[end]);

        
        int mid = (start + end) / 2;
        ListNode* leftSide = _mergeKLists(lists, start, mid);
        ListNode* rightSide = _mergeKLists(lists, mid+1, end);
        return merge2Lists(leftSide, rightSide);
    }

    ListNode* merge2Lists(ListNode* l1, ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;
        
        ListNode* head = nullptr;
        if(l1->val > l2->val){
            head = l2;
            l2 = l2->next;
        }else{
            head = l1;
            l1 = l1->next;
        }

        ListNode* it = head;
        while(l1 && l2){
            if(l1->val > l2->val){
                it->next = l2;
                l2 = l2->next;
            }else{
                it->next = l1;
                l1 = l1->next;
            }
            it = it->next;
        }

        if(l1) it->next = l1;
        else if(l2) it->next = l2;

        return head;
    }
};




/*
Runtime
11
ms
Beats
90.02%
of users with C++
Memory
16.71
MB
Beats
85.62%
of users with C++
*/
/*
    Flatten all lists in one lists and then sorted with Divide & Conquer
*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();

        if(k == 0) return nullptr;
        if(k == 1) return lists[0];
        
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        for(int i = 0; i < k - 1; i++){
            if(!lists[i]){
                if(tail)
                    tail->next = lists[i+1];    
                continue;
            }
            if(!head)
                head = lists[i];
            tail = getTail(lists[i]);
            tail->next = lists[i+1];
        }
        if(!head)
            head = lists[k-1];

        return sortList(head);
    }

    ListNode* getTail(ListNode* head){
        while(head && head->next) 
            head = head->next;

        return head;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* mid = getMidPoint(head);
    
        ListNode* rightSide = sortList(mid->next);
        mid->next = nullptr;
        ListNode* leftSide = sortList(head);

        return merge(leftSide, rightSide);
    }

    ListNode* getMidPoint(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        if(fast && fast->next)
            fast = fast->next;

        return slow;
    }

    ListNode* merge(ListNode* leftSide, ListNode* rightSide){
        if(!leftSide) return rightSide;
        if(!rightSide) return leftSide;

        ListNode* head;

        if(leftSide && rightSide){
            if(leftSide->val <= rightSide->val){
                head = leftSide;
                leftSide = leftSide->next;
            }else{
                head = rightSide;
                rightSide = rightSide->next;
            }
        }

        ListNode* it = head;

        while(leftSide && rightSide){
            if(leftSide->val <= rightSide->val){
                it->next = leftSide;
                leftSide = leftSide->next;
            }else{
                it->next = rightSide;
                rightSide = rightSide->next;
            }
            it = it->next;
        }

        if(leftSide){
            it->next = leftSide;
        }else if(rightSide){
            it->next = rightSide;
        }

        return head;
    }
};







/*
Runtime
117
ms
Beats
20.63%
of users with C++
Memory
16.66
MB
Beats
90.24%
of users with C++
*/
/*
    Sort lists[i] and lists[i+1]
*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();

        if(k == 0) return nullptr;
        if(k == 1) return lists[0];
        
        ListNode* head = lists[0];
        for(int i = 1; i < k; i++){
            head = merge2Lists(head, lists[i]);
        }

        return head;
    }

    ListNode* merge2Lists(ListNode* l1, ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;
        
        ListNode* head = nullptr;
        if(l1->val > l2->val){
            head = l2;
            l2 = l2->next;
        }else{
            head = l1;
            l1 = l1->next;
        }

        ListNode* it = head;
        while(l1 && l2){
            if(l1->val > l2->val){
                it->next = l2;
                l2 = l2->next;
            }else{
                it->next = l1;
                l1 = l1->next;
            }
            it = it->next;
        }

        if(l1) it->next = l1;
        else if(l2) it->next = l2;

        return head;
    }
};