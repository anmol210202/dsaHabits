class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k = (k)%size;
        reverse(nums.begin()+size-k,nums.end());      
        reverse(nums.begin(),nums.end()-k); 
        reverse(nums.begin(),nums.end());
    }
};
