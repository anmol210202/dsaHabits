class Solution {
public:
    int countSegments(string s) {
        istringstream ss(s);
        string word;
        int c=0;
        while(ss>>word) c++;
        return c;
    }
};
