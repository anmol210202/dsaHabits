class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        return (n&(n-1))==0;
        int c=0;
        for(int i=0; i<sizeof(int)*8; i++){
            if(n&(1<<i)) c++;
        }
        cout<<c<<endl;
        return c==1 ? true:false;
    }
};
