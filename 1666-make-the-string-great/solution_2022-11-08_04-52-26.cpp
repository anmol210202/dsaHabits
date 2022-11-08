class Solution {
public:
    string makeGood(string s) {
        stack<char> sta;
        int siz = s.size();
        for(int i=0; i<siz; i++){
            if(sta.empty()) sta.push(s[i]);
            else {
                if(s[i]==sta.top() + 32 || s[i]+32==sta.top()) {
                    sta.pop();
                }
                else sta.push(s[i]);
            }
        }
        string a;
        while(!sta.empty()){
            // cout<<sta.top()<<" ";
            a.push_back(sta.top());
            sta.pop();
        }
        reverse(a.begin(),a.end());
        return a;
    }
};
