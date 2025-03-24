class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> map;
        int startPoint = 0;
        int maxLength = 0;

        for(int i=0; i<s.size(); i++){
            if(map.find(s[i])!=map.end() && startPoint<=map[s[i]] ){
                startPoint = map[s[i]]+1;
            }
            map[s[i]]=i;
            maxLength=max(maxLength,i-startPoint+1); 
        }
        return maxLength;
    }
};
