class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> v(128);
        int n=s.length();
        int temp=0;
        int x=0;
        int mx=INT_MIN;        
        for(int i=0; i<n; i++){
            v[s[i]]++;
            temp++;
            if(v[s[i]]>1){
                for(int j=0; j<128; j++) {
                    v[j]=0;
                }
                temp--;
                i=x++;
                mx=max(mx,temp);
                temp=0;
            }
        }
        return max(mx,temp);
        
    }
};
