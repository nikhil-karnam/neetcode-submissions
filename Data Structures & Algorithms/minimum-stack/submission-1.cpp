class MinStack {
public:
std::vector<int> v;
    MinStack() {
        
    }
    
    void push(int val) {
        v.push_back(val);
    }
    
    void pop() {
        v.pop_back();
    }
    
    int top() {
        return v.back();
    }
    
    int getMin() {
        return *std::min_element(v.begin(), v.end());
    }
};
