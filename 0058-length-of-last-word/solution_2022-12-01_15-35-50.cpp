class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans =0;
        bool x=true;
        for(int i=s.size()-1; i>=0; i--){
            if(s[i]!=' '){
                ans++;
                x=false;
            }else{
                if(!x){
                    return ans;
                }
                x=true;
            }
        }
        return ans;
    }
};
