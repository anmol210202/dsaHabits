class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        for(int i=0; i<nums.size(); i++){
            int cmt = target-nums[i];
            if(map.find(cmt)!=map.end()){
                return {map[cmt],i};
            }
            map[nums[i]]=i;
        }
        return {};
    }
};
