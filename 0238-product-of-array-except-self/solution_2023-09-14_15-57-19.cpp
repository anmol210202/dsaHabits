class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int l=1, r=1,n=nums.size();
        vector<int> left(n,1),right(n,1),result(n,1);
        for(int i=0; i<n; i++){
            left[i]=l;
            l*=nums[i];
        }
        for(int i=n-1; i>=0; i--){
            right[i]=r;
            r*=nums[i];
        }
        for(int i=0; i<n; i++){
            result[i]=left[i]*right[i];
        }
        return result;
    }
};
