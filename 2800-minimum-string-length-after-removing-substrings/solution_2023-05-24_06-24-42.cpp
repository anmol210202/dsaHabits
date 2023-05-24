class Solution {
public:
  int minLength(const std::string& s) {
    std::stack<char> st;

    for (auto& e : s) {
        if (st.empty()) {
            st.push(e);
        } else {
            char t = st.top();
            if ((t == 'A' && e == 'B') || (t == 'C' && e == 'D')) {
                st.pop();
            } else {
                st.push(e);
            }
        }
    }

    return st.size();
}
};
