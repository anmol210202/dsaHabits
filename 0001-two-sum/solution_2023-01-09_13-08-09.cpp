class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> v(n);
        for(int i = 0; i < n; i++) {
            v[i] = nums[i];
        }
        sort(nums.begin(), nums.end());
        int first_posi, second_posi;
        pair<int, bool> p;
        for(int i = 0; i < n; i++) {
            int find_element = target  - nums[i];
            p = check(n, nums, find_element);
            if(p.second) {
                for(int j = 0; j < n; j++) {
                    if(nums[i] == v[j]) {
                        first_posi = j;
                        break;
                    }
                }
                for(int j = n - 1; j >= 0; j--) {
                    if(p.first == v[j] && j != first_posi) {
                        second_posi = j;
                        break;
                    }
                }
                v.clear();
                v.insert(v.end(),{first_posi,second_posi});
                sort(v.begin(), v.end());
                return v;
            }
        }
        return  v;
    }
    
    pair<int, bool> check(int n, vector<int> &nums, int find_element) {
        pair<int, int> p;
        int first = 0, last = n - 1;
        while(first <= last) {
            int mid = first + ((last - first) / 2);
            
            if(nums[mid] == find_element)  {
                p.first = nums[mid];
                p.second = true;
                return p;
            }
            else if(nums[mid] > find_element) 
                    last = mid - 1;
            else 
                    first = mid + 1;
        }
        p.first = -1;
        p.second = false;
        return p;
    }
};
