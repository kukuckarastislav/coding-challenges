#include <unordered_map>
using namespace std;

/*
Runtime
305
ms
Beats
96.64%
of users with C++
Memory
168.27
MB
Beats
92.99%
of users with C++
*/
struct ListNode2 {
    int key;
    int val;
    ListNode2 *next;
    ListNode2 *prev;
    ListNode2(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    int n;
    ListNode2* head;
    ListNode2* tail;
    unordered_map<int, ListNode2*> mp;

    ListNode2* useNode(int key){

        auto itCurr = mp.find(key);
        if(itCurr == mp.end())
            return nullptr;

        ListNode2* curr = itCurr->second;
        if(head != curr){
            ListNode2* cp = curr->prev;
            ListNode2* cn = curr->next;

            cp->next = cn;
            if(curr->next)
                cn->prev = cp;
            else
                tail = cp;
            
            curr->prev = nullptr;
            curr->next = head;
            head->prev = curr;
            head = curr;
        }

        return curr;
    }

public:
    LRUCache(int capacity) : capacity(capacity), head(nullptr), tail(nullptr), n(0) {}
    
    int get(int key) {
        
        ListNode2* node = useNode(key);
        if(node)
            return node->val;
        
        return -1;
    }
    
    void put(int key, int value) {

        ListNode2* curr = useNode(key);
        if(curr){
            curr->val = value;
            return;
        }

        curr = new ListNode2(key, value);
        if(n < capacity){
            if(head){
                curr->next = head;
                head->prev = curr;
            }
            head = curr;
            if(!tail){
                tail = curr;
            }
            n++;
        }else{
            curr->next = head;
            head->prev = curr;
            head = curr;

            ListNode2* lastNode = tail;
            tail = tail->prev;
            tail->next = nullptr;
            mp.erase(lastNode->key);
        }

        mp[key] = curr;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(){
    int capacity = 2;
    int x;
    LRUCache* obj = new LRUCache(capacity);
    obj->put(1,1);
    obj->put(2,2);
    x = obj->get(1);
    obj->put(3,3);
    x = obj->get(2);
    obj->put(4,4);
    x = obj->get(1);
    x = obj->get(3);
    x = obj->get(4);

    return 0;
}



/////////////////////////////////////////////////////////////////////////////////////////
#include <unordered_map>
using namespace std;

/*
TLE - because list is not double linked, and removing last element is exspensive
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    int n;
    ListNode* head;
    unordered_map<int, int> mp;

    void updateList(int key){
        if(head && head->val == key) 
            return;

        ListNode* it = head;
        while(it && it->next){
            if(it->next->val == key)
                break;
            it = it->next;
        }

        if(it->next){
            ListNode* temp = it->next;
            it->next = it->next->next;
            temp->next = head;
            head = temp;
        }
    }

public:
    LRUCache(int capacity) : capacity(capacity) {
        n = 0;
        head = nullptr;
    }
    
    int get(int key) {
        
        if(!mp.count(key))
            return -1;

        updateList(key);
        
        return mp[key];
    }
    
    void put(int key, int value) {

        if(mp.count(key)){
            updateList(key);
            mp[key] = value;
            return;
        }

        if(n < capacity){
            // add new node to front of list
            ListNode* curr = new ListNode(key);
            if(head){
                curr->next = head;   
            }
            head = curr;
            n++;
        }else{
            ListNode* curr = new ListNode(key);
            curr->next = head;
            head = curr;

            while(curr && curr->next && curr->next->next){
                curr = curr->next;
            }
            if(curr && curr->next){
                mp.erase(curr->next->val);
                curr->next = nullptr;
            }
        }

        mp[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(){
    int capacity = 2;
    int x;
    LRUCache* obj = new LRUCache(capacity);
    obj->put(1,1);
    obj->put(2,2);
    x = obj->get(1);
    obj->put(3,3);
    x = obj->get(2);
    obj->put(4,4);
    x = obj->get(1);
    x = obj->get(3);
    x = obj->get(4);

    return 0;
}