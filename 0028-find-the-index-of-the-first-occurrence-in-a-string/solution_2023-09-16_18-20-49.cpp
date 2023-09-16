class Solution {
public:
    int strStr(string haystack, string needle) {
        // return haystack.find(needle);4
        int n = haystack.length() , m = needle.length();
        if(m==0) return 0;
        int needleSum = 0 , windowSum = 0;
        for(auto &e:needle) needleSum+=e;
        for(auto i=0; i<m; i++) windowSum+=haystack[i];
        for(int i=m; i<=n; i++){
            if(windowSum == needleSum and  haystack.substr(i-m,m) == needle) return i-m;
            windowSum+=(haystack[i]-haystack[i-m]); 
        }
        return -1;
    }
};
