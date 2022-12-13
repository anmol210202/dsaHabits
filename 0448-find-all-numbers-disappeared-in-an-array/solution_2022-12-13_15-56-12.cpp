class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int s = nums.size();
        vector<int> x(s+1,0);
        vector<int> ans;
        for(auto &e:nums) x[e]++;
        for(int i=0; i<s+1; i++){
            if(x[i]==0 and i!=0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
