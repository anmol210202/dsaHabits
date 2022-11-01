class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k = (k)%size;
        vector<int> temp;
        for(int i=0; i<size; i++){
            temp.push_back(nums[(i+size-k)%size]);
            // cout<<temp[i]<<" ";
        }
        nums=temp;
    }
};
