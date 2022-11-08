class Solution {
public:
    string makeGood(string s) {
        stack<char> sta;
        for(int i=0; i<s.size(); i++){
            if(sta.empty()) sta.push(s[i]);
            else {
                if(s[i]==sta.top() + 32 || s[i]+32==sta.top()) {
                    sta.pop();
                }
                else sta.push(s[i]);
            }
        }
        s.clear();
        while(!sta.empty()){
            // cout<<sta.top()<<" ";
            s.push_back(sta.top());
            sta.pop();
        }
        reverse(s.begin(),s.end());
        return s;
    }
};
