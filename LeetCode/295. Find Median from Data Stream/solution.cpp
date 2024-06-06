



/*
Runtime
1196
ms
Beats
5.00%
of users with C++
Memory
128.17
MB
Beats
9.44%
of users with C++
*/

struct DLNode {
    int val = 0;
    DLNode* next = nullptr;
    DLNode* prev = nullptr;

    DLNode(int _val){
        val = _val;    
    }

    DLNode(int _val, DLNode* _prev, DLNode* _next){
        val = _val;
        next = _next;
        prev = _prev;
    }
};



class MedianFinder {
private:
    DLNode* head = nullptr;
    DLNode* tail = nullptr;
    DLNode* mid = nullptr;
    int n = 0;
public:
    MedianFinder() {}
    
    void addNum(int num) {
        if(!head){
            head = new DLNode(num);
            mid = head;
            tail = head;
        }else if(head->val >= num){
            DLNode* newNode = new DLNode(num, nullptr, head);
            head->prev = newNode;
            head = newNode;
            if(n % 2 == 1)
                mid = mid->prev;
        }else if(tail->val <= num){
            DLNode* newNode = new DLNode(num, tail, nullptr);
            tail->next = newNode;
            tail = newNode;
            if(n % 2 == 0)
                mid = mid->next;
        }else{
            DLNode* it = head;
            while(it && it->next && it->next->val <= num){
                it = it->next;
            }
            DLNode* newNode = new DLNode(num, it, it->next);
            it->next->prev = newNode;
            it->next = newNode;

            if(num < mid->val){
                if(n % 2 == 1)
                    mid = mid->prev;
            }else{
                if(n % 2 == 0) 
                    mid = mid->next;
            }
        }
        n++;
    }
    
    double findMedian() {
        if(n % 2)
            return (double)mid->val;
        else
            return (mid->val + mid->next->val) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */