class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> m;
        for(int i=0;i<nums.size();i++){
            m.insert(nums[i]);
        }
        for(auto &ip:m){
            cout<<ip<<" ";
        }
        auto it=m.rbegin();
        advance(it,k-1);
        return *it;
    }
};
