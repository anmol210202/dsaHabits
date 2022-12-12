class Solution {
public:
    char findTheDifference(string s, string t) {
        char c = 0;
        for(auto &e:t) c^=e;
        for(auto &e:s) c^=e;
        return c;
    }
};
