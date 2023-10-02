class MinStack {
public:
    
    vector<int> v;

    MinStack() {
        
    }
    
    void push(int val) {
        v.push_back(val);
    }
    
    void pop() {
        if(!v.empty()) v.pop_back();
    }
    
    int top() {
        return v.back();
    }
    
    int getMin() {
        auto minEle = min_element(v.begin(),v.end());

        if(minEle != v.end()) return *minEle;
        return -1;
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
