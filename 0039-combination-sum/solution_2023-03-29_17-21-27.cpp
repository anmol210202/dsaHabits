class Solution {
public:
    void r(vector<int> &can ,int i, int t,int sum,vector<int> &tmp,set<vector<int>> &ans){
        if(sum==t) ans.insert(tmp);
        if(i==can.size() or sum>t) return;
        r(can,i+1,t,sum,tmp,ans);
        tmp.push_back(can[i]);
        r(can,i,t,sum+can[i],tmp,ans);
        r(can,i+1,t,sum+can[i],tmp,ans);
        tmp.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> tmp;
        set<vector<int>> ans;
        vector<vector<int>> a;
        r(candidates,0,target,0,tmp,ans);
        for(auto &e:ans) a.push_back(e);
        return a;
    }
};
