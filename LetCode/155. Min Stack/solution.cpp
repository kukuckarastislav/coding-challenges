#include <stack>
#include <vector>
using namespace std;


/*
Runtime
9
ms
Beats
97.30%
of users with C++
Memory
19.78
MB
Beats
98.50%
of users with C++
*/
class MinStack {
private:
    vector<pair<int, int>> stk;
public:
    MinStack() {}
    
    void push(int val) {
        if(stk.empty()){
            stk.push_back({val, val});
        }else{
            stk.push_back({val, min(stk.back().second, val)});
        }
    }
    
    void pop() {
        stk.pop_back();
    }
    
    int top() {
        return stk.back().first;
    }
    
    int getMin() {
        return stk.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


/*
Runtime
16
ms
Beats
68.15%
of users with C++
Memory
21.09
MB
Beats
33.28%
of users with C++
*/
class MinStack {
private:
    stack<pair<int, int>> stk;
public:
    MinStack() {}
    
    void push(int val) {
        if(stk.empty()){
            stk.emplace(val, val);
        }else{
            stk.emplace(val, min(stk.top().second, val));
        }
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;
    }
};