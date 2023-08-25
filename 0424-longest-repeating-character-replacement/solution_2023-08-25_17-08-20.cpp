class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size(), start = 0 , maxLength = 0 , maxCount=0;
        map<char,int> m;
        for(int end=0; end<n; end++){
            m[s[end]]++;
            maxCount = max(maxCount , m[s[end]]);

            while(end - start + 1 - maxCount > k){
                m[s[start]]--;
                start++;
            }
            maxLength = max(maxLength , end - start + 1);
        }
        return maxLength;
    }
};

