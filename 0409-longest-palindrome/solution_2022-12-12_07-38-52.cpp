class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> m;
        for(auto &e:s) m[e]++;
        int a=0,o=0;
        for(auto &e:m){
            if(e.second%2==1){
                o=1;
                a+=--e.second;
            }
            else a+=e.second;
        }
        return o==1 ? ++a:a;
    }
};
