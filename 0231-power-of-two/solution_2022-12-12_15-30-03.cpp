class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==-2147483648) return false;
        int c=0;
        for(int i=0; i<sizeof(int)*8; i++){
            if(n&(1<<i)) c++;
        }
        cout<<c<<endl;
        return c==1 ? true:false;
    }
};
