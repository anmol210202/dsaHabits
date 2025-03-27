class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map;
        stack<int> st;

        for(int i=0; i<nums2.size(); i++){
            int ele = nums2[i];

            while(!st.empty() && ele > st.top()){
                map[st.top()] = ele;
                st.pop();
            }
            st.push(ele);
        }

        vector<int> ans(nums1.size(),-1);

        for(int i=0; i<nums1.size(); i++){
            if(map.find(nums1[i])!=map.end()){
                ans[i] = map[nums1[i]];
            }
        }

        return ans;
    }
};
