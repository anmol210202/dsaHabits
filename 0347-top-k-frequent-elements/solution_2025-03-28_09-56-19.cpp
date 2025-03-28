class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;

        for(auto num:nums) map[num]++;

        priority_queue<pair<int,int> , vector<pair<int,int>>,greater<pair<int,int>>> minPairHeap;

        for(auto [num,count]:map){
            minPairHeap.push({count,num});
            if(minPairHeap.size()>k){
                minPairHeap.pop();
            }
        }

        vector<int> ans;

        while(!minPairHeap.empty()){
            ans.push_back(minPairHeap.top().second);
            minPairHeap.pop();
        }

        return ans;
    }
};
