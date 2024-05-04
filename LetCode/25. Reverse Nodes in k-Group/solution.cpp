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
3
ms
Beats
98.91%
of users with C++
Memory
14.91
MB
Beats
77.30%
of users with C++
*/
class Solution {
public:

    // newStart, newEnd, oldNextOfStart
    tuple<ListNode*, ListNode*, ListNode*> reverse(ListNode* start, int k){

        ListNode* it = start;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        while(it && it->next && k){   
            next = it->next;
            it->next = prev;
            prev = it;
            it = next;
            k--;
        }

        next = it->next;
        it->next = prev;
        return make_tuple(it, start, next);
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(k == 1) 
            return head;

        int n = getLength(head);
        if(n == 1) 
            return head;

        int m = n/k;

        ListNode* start = head;
        ListNode* lastEnd = nullptr;
        ListNode* lastOldNext = nullptr;

        auto [newStart, newEnd, oldNext] = reverse(start, k-1);
        head = newStart;
        lastEnd = newEnd;
        lastOldNext = oldNext;
        start = oldNext;

        for(int i = 1; i < m; i++){
            auto [newStart, newEnd, oldNext] = reverse(start, k-1);
       
            lastEnd->next = newStart;
            
            lastEnd = newEnd;
            lastOldNext = oldNext;
            start = oldNext;
        }
        lastEnd->next = lastOldNext;

        return head;
    }

    int getLength(ListNode* head){
        int n = 0;
        ListNode* it = head;
        while(it){
            it = it->next;
            n++;
        }
        return n;
    }
};


int main(){


    int k = 4;
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};

    ListNode* head = nullptr;
    ListNode* it;
    for(int x : arr){
        if(!head){
            head = new ListNode(x);
            it = head;
            continue;
        }

        it->next = new ListNode(x);
        it = it->next;
    }

    Solution s;
    head = s.reverseKGroup(head, k);

    return 0;
}