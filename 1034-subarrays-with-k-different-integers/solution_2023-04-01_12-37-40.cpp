class Solution {
public:
    int atMost(vector<int> arr,int k){
        int l=0,c=0;
        unordered_map<int,int> m;
        for(int r=0;r<arr.size();r++){
            if(!m[arr[r]]++) k--; 
            while(k<0){
                if(!--m[arr[l]]) k++;
                l++;
            }
            c+=r-l+1;
        }
        return c;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return atMost(nums,k)-atMost(nums,k-1);
    }
};
