class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0;
        int j=0;
        vector<int> temp;
        while(i<m and j<n){
            (nums1[i]<nums2[j] ? temp.push_back(nums1[i]):temp.push_back(nums2[j]));
            (nums1[i]<nums2[j] ? i++:j++);
        }
        while(i<m){
            temp.push_back(nums1[i]);
            i++;
        }
        while(j<n){
            temp.push_back(nums2[j]);
            j++;
        }
        for(int k=0; k<m+n; k++){
            nums1[k]=temp[k];
        }
    }
};
