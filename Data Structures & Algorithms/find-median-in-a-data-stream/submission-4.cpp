#include <queue>
#include <vector>

class MedianFinder {
public:
    std::priority_queue<int> left;
    std::priority_queue<int, std::vector<int>, std::greater<int>> right;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        //pass through both queues to find middle number.
        left.push(num);
        right.push(left.top());
        left.pop();
        int mid = right.top();
        right.pop();

        if(left.size() == right.size()){
            left.push(mid);
        }
        else{
            right.push(mid);
        }
    }
    
    double findMedian() {
        if(left.size() > right.size()){
            return left.top();
        }
        //decimal to avoid truncation
        return (left.top() + right.top()) / 2.0;
    }
};
