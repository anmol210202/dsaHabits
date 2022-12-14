class Solution {
public:
    string DTB(int n){
        string s;
        while(n){
            if(n&1) s+='1';
            else s+='0';
            n>>=1;
        }
        return s;
    }

    int hammingDistance(int x, int y) {
        string X,Y;
        X = DTB(x);
        Y = DTB(y);
        int n = min(X.size(),Y.size()) , a=0 , m = max(X.size(),Y.size());
        for(int i=0; i<n;i++) if(X[i]!=Y[i]) a++;
        for(int i=n; i<m; i++){
            if(X.size()>Y.size()){if(X[i]=='1') a++;}
            else{if(Y[i]=='1') a++;}
        }
        return a;
    }
};
