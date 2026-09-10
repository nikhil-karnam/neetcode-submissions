#include <queue>
#include <vector>

class MedianFinder {
public:
    std::priority_queue<int> left;
    std::priority_queue<int, std::vector<int>, std::greater<int>> right;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        left.push(num);
        right.push(left.top());
        left.pop();

        if(right.size() > left.size()){
            left.push(right.top());
            right.pop();
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
