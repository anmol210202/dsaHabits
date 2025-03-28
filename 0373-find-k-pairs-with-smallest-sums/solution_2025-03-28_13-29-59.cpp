class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<tuple<int, int, int> ,vector<tuple<int, int, int>> , greater<tuple<int, int, int>>> maxHeap;

        for(int i=0; i<min((int)nums1.size(),k); i++){      // instead of nums1.size() we will have k
            maxHeap.push({nums1[i]+nums2[0],i,0});
        }
        vector<vector<int>> ans;

        while(!maxHeap.empty() && k--){
            int sum = get<0>(maxHeap.top());
            int x = get<1>(maxHeap.top());
            int y = get<2>(maxHeap.top());
            maxHeap.pop();
            ans.push_back({nums1[x],nums2[y]});
            if(y!=nums2.size()-1){
                maxHeap.push({nums1[x]+nums2[y+1],x,y+1});
            }
        }

        return ans;

    }
};
