class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int sum = 0;
        unordered_map<int,int> prefixCount;

        prefixCount[0]=1;

        for(int num:nums){
            sum+=num;
            if(prefixCount.find(sum-k) != prefixCount.end()){
                count+=prefixCount[sum-k];
            }

            prefixCount[sum]++;
        }
        return count;
    }
};
