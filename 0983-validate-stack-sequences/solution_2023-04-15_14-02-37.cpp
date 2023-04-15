class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int i=0;
        for(auto &e:pushed){
            s.push(e);
            while(!s.empty() and s.top()==popped[i]) s.pop(), i++;
        }
        return i==popped.size();
        // return s.empty()
    }
};
