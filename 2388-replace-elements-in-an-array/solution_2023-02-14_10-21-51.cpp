class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int> m;
        for(int i=0; i<nums.size(); i++) m[nums[i]]=i;
        for(auto &e:operations){
            nums[m[e[0]]]=e[1];
            auto nodeHandler=m.extract(e[0]);
            nodeHandler.key()=e[1];
            m.insert(move(nodeHandler));
        }
        return nums;
    }
};
