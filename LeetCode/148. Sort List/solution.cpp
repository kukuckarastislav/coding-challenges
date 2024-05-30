

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


/*
Runtime
92
ms
Beats
99.09%
of users with C++
Memory
54.46
MB
Beats
92.50%
of users with C++
*/
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return _sortList(head);
    }

private:
    ListNode* _sortList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* mid = getMidPoint(head);
    
        ListNode* rightSide = _sortList(mid->next);
        mid->next = nullptr;
        ListNode* leftSide = _sortList(head);

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


int main(){

    int arr[] = {4,2,1,3};
    const int n = 4;

    ListNode* head;
    ListNode* it;
    for(int i = 0; i < n; i++){
        if(i == 0){
            head = new ListNode(arr[i]);
            it = head;
        }else{
            it->next = new ListNode(arr[i]);
            it = it->next;
        }
    }

    Solution sol;
    head = sol.sortList(head);

    return 0;
}



/*
Runtime
98
ms
Beats
96.82%
of users with C++
Memory
54.37
MB
Beats
97.69%
of users with C++
*/
class Solution {
public:
    ListNode* sortList(ListNode* head) {

        if(!head || !head->next) return head;

        ListNode* end = head;
        while(end && end->next)
            end = end->next;

        return _sortList(head, end);
    }

private:
    ListNode* _sortList(ListNode* head, ListNode* end) {
        if(!head)
            return nullptr;
        
        if(!head->next)
            return head;

        if(head == end){
            head->next = nullptr;
            return head;
        }
        if(head->next == end){
            // we have 2 two nodes
            if(head->val > end->val){
                end->next = head;
                head->next = nullptr;
                return end;
            }else{
                end->next = nullptr;
                return head;
            }
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        if(fast && fast->next)
            fast = fast->next;


        ListNode* rightSide = _sortList(slow->next, fast);
        slow->next = nullptr;
        ListNode* leftSide = _sortList(head, slow);

        if(leftSide && rightSide){
            if(leftSide->val <= rightSide->val){
                head = leftSide;
                leftSide = leftSide->next;
            }else{
                head = rightSide;
                rightSide = rightSide->next;
            }
        }else if(leftSide){
            head = leftSide;
            leftSide = leftSide->next;
        }else if(rightSide){
            head = rightSide;
            rightSide = rightSide->next;
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
};