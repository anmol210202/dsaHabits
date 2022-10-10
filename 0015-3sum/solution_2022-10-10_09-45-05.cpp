class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       sort(nums.begin(),nums.end());
		set<vector<int>>set;
		vector<vector<int>> ans;

		for(int i= 0;i<nums.size();i++){
			int j = i+1;
			int k = nums.size()-1;


			while(j<k){
				int sum = nums[i]+nums[j]+nums[k];
				if (sum==0){
					set.insert({nums[i],nums[j],nums[k]});
					j++;
					k--;
				}
				else if(sum>0){
					k--;
				}
				else j++;
			}
		}
		for(auto i : set){
			ans.push_back(i);
		}
    
    return ans;
    }
};
