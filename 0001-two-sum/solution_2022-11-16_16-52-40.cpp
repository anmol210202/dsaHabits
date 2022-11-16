class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int first_value = -1, last_value = -1;
        int n = nums.size();
        vector<int> vv(n);
        for(int i = 0; i < n; i++) {
            vv[i] = nums[i];
        }
        sort(nums.begin(), nums.end());
        vector<int> v;
        for(int i = 0; i < n; i++) {
            int first = 0, last = n - 1;
            while(first <= last) {
                int mid = first + ((last - first) / 2);
                
                if(nums[mid] + nums[i] == target) {
                    first_value = nums[i];
                    last_value = nums[mid];
                    break;
                }
                else if(nums[mid] + nums[i] < target) 
                    first = mid + 1;
                else 
                    last = mid - 1;
            }
            if(first_value != -1) {
                break;
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(first_value == vv[i]) {
                v.push_back(i);
                break;
            }
        }
        for(int i = n - 1; i >= 0; i--) {
            if(last_value == vv[i]) {
                v.push_back(i);
                break;
            }
        }
        sort(v.begin(), v.end());
        return v;
    }
};
