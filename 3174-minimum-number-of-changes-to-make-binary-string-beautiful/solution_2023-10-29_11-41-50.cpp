class Solution {
public:
    int minChanges(string s) {
        int ans = 0 , count = 0 , prev = s[0];

        for(auto &e:s){
            if(e==prev) count++;
            else {
                if(count%2){
                    ans++;
                    count = 0;
                } else count = 1;
                prev = e;
            }
        } 
        
        return ans;
    }
};
