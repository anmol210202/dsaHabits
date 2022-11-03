class Solution {
public:
    string reversed(string s) {
         string t = s;
        reverse(t.begin(), t.end());
        return t;
    }
    int longestPalindrome(vector<string>& words) {
        int ans = 0, middle = 0;
        unordered_map<string, int> cnt;
        for (auto word : words) cnt[word]++;
        for (auto [s, f] : cnt) {
            string rev = reversed(s);
            if (s != rev) {
                if (cnt.count(rev)) {
                    ans += min(cnt[s], cnt[rev]);
                }
                
            } else {
                ans += f;
                if (f & 1) {
                    middle = 1;
                    ans -= 1;
                }
            }
        }
        ans += middle;
        return 2 * ans;
    }
};
