class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int s= nums.size();
        vector<string> v;
        if(s==0) return v; 
        int c = nums[0];

        for(int i=0; i<s ; i++){
            if(i==s-1 or nums[i]+1!=nums[i+1]){
                if(nums[i]!=c) v.push_back(to_string(c) + "->" + to_string(nums[i]));
                else v.push_back(to_string(c));
                if(i!=s-1) c=nums[i+1];
            }
        }

        return v;
    }
};
