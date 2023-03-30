class Solution {
public:
    void r(vector<int> &can ,int i, int t,vector<int> &tmp,vector<vector<int>> &ans){
        if(t==0) {ans.push_back(tmp);return;}
        for(int j=i; j<can.size(); j++){
            if(can[j]>t) continue;
            tmp.push_back(can[j]);
            r(can,j,t-can[j],tmp,ans);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> tmp;
        vector<vector<int>> ans;
        r(candidates,0,target,tmp,ans);
        return ans;
    }
};
