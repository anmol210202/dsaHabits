class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        auto pivot = std::is_sorted_until(nums.rbegin(), nums.rend());
        if (pivot != nums.rend()) {
            auto change = std::upper_bound(nums.rbegin(), pivot, *pivot);
            std::swap(*pivot, *change);
        }
        std::reverse(nums.rbegin(), pivot);
    }
};

