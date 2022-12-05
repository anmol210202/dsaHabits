// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l=1 , r=n,m=l+(r-l)/2;
        while(l<=r){
            bool x = isBadVersion(m);
            if(x) r=m-1;
            else l=m+1;
            m=l+(r-l)/2;
        }
        return l;
    }
};
