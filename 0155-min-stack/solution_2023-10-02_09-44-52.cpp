class MinStack {
public:
    
    stack<int> st;
    stack<int> minSt;

    MinStack() {
        
    }
    
    void push(int val) {
        if(minSt.empty() or val<=minSt.top()) minSt.push(val);
        st.push(val);
    }
    
    void pop() {
        if(st.top()==minSt.top()){
            st.pop();
            minSt.pop();
        } else st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        if(!minSt.empty()) return minSt.top();
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
