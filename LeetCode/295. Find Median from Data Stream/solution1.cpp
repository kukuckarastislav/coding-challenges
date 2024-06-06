#include <queue>
using namespace std;



/*
Runtime
267
ms
Beats
60.67%
of users with C++
Memory
121.66
MB
Beats
81.86%
of users with C++
*/
class MedianFinder {
public:
    priority_queue<int> smallerGroup;
    priority_queue<int, vector<int>, greater<int>> largerGroup;
    
    MedianFinder() {}

    void addNum(int num) {
        if(smallerGroup.empty() || num <= smallerGroup.top())
            smallerGroup.push(num);
        else
            largerGroup.push(num);


        if( smallerGroup.size() > largerGroup.size()+1 ){
            largerGroup.push(smallerGroup.top());
            smallerGroup.pop();
        }else if( smallerGroup.size() < largerGroup.size() ){
            smallerGroup.push(largerGroup.top());
            largerGroup.pop();
        }
    }

    double findMedian() {
        if (smallerGroup.size() > largerGroup.size()) 
            return smallerGroup.top();
        else 
            return (smallerGroup.top() + largerGroup.top()) / 2.0;
    }
};
