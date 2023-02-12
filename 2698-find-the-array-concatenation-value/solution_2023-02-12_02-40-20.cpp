class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long j=nums.size()-1,i=0,ans=0;
        while(j>=i){
            if(i==j) ans+=nums[i];
            else{
                string x;
                x=to_string(nums[i])+to_string(nums[j]);
                ans+=stoi(x);
            }
            j--;
            i++;
        }
        return ans;
    }
};
