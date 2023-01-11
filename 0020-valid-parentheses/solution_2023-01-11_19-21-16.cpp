class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for(auto &x:s)
            if(stack.empty()) stack.push(x);
            else if(((x-stack.top())==2 or x-stack.top()==1) and (x-stack.top())!=0) stack.pop();
            else stack.push(x);
        return stack.empty() ? true : false;
    }
};
