class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        // vector<int> v;
        int m=INT_MIN;
        for(int i=0; i<nums1.size(); i++){
            auto j=nums2.rend()-lower_bound(nums2.rbegin(),nums2.rend(),nums1[i]);
            // cout<<j<<endl;
            // v.push_back(j-i-1);
            int tmp =j-i-1;
            m=max(m,tmp);
        }
        // return *max_element(v.begin(),v.end());
        return m<0 ? 0:m;
    }
};
