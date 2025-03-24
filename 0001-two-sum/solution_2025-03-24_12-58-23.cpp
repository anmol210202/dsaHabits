class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n= nums.size();
        vector<pair<int,int>> map(n);
        for(int i=0; i<n; i++){
            map[i]={nums[i],i};
        }
        sort(map.begin(),map.end());
        int i=0;
        int j=nums.size()-1;
        while(i<j){
            int sum=map[i].first+map[j].first;
            if(sum==target){
                return {map[i].second,map[j].second};
            } else if(sum>target){
                j--;
            } else {
                i++;
            }
        }
        return {};
    }
};
