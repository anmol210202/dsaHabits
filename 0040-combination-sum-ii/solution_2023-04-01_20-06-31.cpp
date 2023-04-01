class Solution {
public:
    vector<int> tmp;
    vector<vector<int>> ans;
    void r(vector<int> &can,int t, int i){
        // if(t<0) return ;
        if(t==0){
            ans.push_back(tmp);
            return;
        }
        for(int j=i; j<can.size(); j++){
            if(t-can[j]<0) break;
            tmp.push_back(can[j]);
            r(can,t-can[j],j+1);
            tmp.pop_back();
            while (j + 1 < can.size() && can[j] == can[j + 1]) j++;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& can, int t) {
        sort(can.begin(),can.end());
        r(can,t,0);
        return ans;
    }
};
