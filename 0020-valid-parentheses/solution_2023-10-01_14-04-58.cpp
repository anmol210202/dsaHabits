class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n= s.size();

        for(int i=0; i<n; i++){
            if(!st.empty()){
                char temp= st.top();
                // cout<<temp-s[i];
                if(temp - s[i]==-1 or temp - s[i]==-2) st.pop();
                else st.push(s[i]);
            } else {
                st.push(s[i]);
            }
        }

        return st.empty();
    }
};
