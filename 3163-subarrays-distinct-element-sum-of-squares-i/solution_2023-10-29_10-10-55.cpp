class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans = 0 , n= nums.size();
        for(int i=0; i<n; i++){
            unordered_map<int,int> um;
            int count = 0 ;
            for(int j=i; j<n; j++){
                um[nums[j]]++;
                if(um[nums[j]]==1) count++;
                ans += count * count;
            }
        }
        return ans;
    }
};

