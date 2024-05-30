#include <cstddef>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


/*
Runtime
3
ms
Beats
91.03%
of users with C++
Memory
12.87
MB
Beats
75.47%
of users with C++
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node* it = head;

        Node* headNew = new Node(it->val);
        Node* itNew = headNew;
        it = it->next;

        while(it){
            itNew->next = new Node(it->val);
            itNew = itNew->next;
            it = it->next;
        }

        it = head;
        itNew = headNew;
        Node* it2 = it;
        Node* itNew2 = itNew;

        while(it){

            if(it->random){
                it2 = head;
                itNew2 = headNew;
                while(it2){
                    if(it->random == it2){
                        itNew->random = itNew2;
                        break;
                    }
                    it2 = it2->next;
                    itNew2 = itNew2->next;
                }
            }

            it = it->next;
            itNew = itNew->next;
        }


        return headNew;
    }
};

