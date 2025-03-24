class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int windowSum = 0;
        double avgSum = 0;

        if (n < k)
            return -1;

        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }
        avgSum = static_cast<double>(windowSum) / k;

        for (int i = k; i < n; i++) {
            windowSum += nums[i] - nums[i - k];
            avgSum = max(avgSum, static_cast<double>(windowSum) / k);
        }
        return avgSum;
    }
};
