class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=0,u=arr.size()-1,m=l+(u-l)/2;
        while(l<u){
            if(arr[m]<arr[m+1]) l=m+1;
            else u=m;
            m=l+(u-l)/2;
        }
        return l;
    }
};
