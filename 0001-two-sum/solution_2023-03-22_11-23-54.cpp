class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indices(nums.size());
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int i, int j) { return nums[i] < nums[j]; });
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            int sum = nums[indices[i]] + nums[indices[j]];
            if (sum == target) {
                return {indices[i], indices[j]};
            } else if (sum < target) {
                i++;
            } else {
                j--;
            }
        }
        return {};
    }
};

