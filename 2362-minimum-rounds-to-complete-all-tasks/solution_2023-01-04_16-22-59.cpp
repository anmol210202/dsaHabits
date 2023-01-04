class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> m;
        int ans = 0;
        for(auto &e:tasks) m[e]++;
        for(auto &e:m){
            if(e.second==1) return -1;
            if(e.second>=3){
                if(e.second%3==0) ans+=e.second/3;
                else ans+=e.second/3+1;
            }
            else ans++;
        }
        return ans;
    }
};
