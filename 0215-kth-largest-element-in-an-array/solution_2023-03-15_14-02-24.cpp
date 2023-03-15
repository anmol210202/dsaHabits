class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> q;
        for(auto &e:nums){
            if(q.size()<k) q.push(e);
            else if(q.top()<e) q.pop(),q.push(e);
        }
        return q.top();
    }
};
