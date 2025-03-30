class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int left = 0, rgt = nums.size() - 1;
            while (left <= rgt) {
                int mid = left + (rgt - left) / 2;
                if (nums[mid] == target)
                    return mid;
                
                if (nums[left] <= nums[mid]) {
                    // If target is within the sorted left half
                    if (target >= nums[left] && target < nums[mid]) rgt = mid - 1;
                    else left = mid + 1;
                } else {
                    // Right half is sorted
                    if (target > nums[mid] && target <= nums[rgt]) left = mid + 1;
                    else rgt = mid - 1;
                }
            }
            return -1;
        }
    };
    
