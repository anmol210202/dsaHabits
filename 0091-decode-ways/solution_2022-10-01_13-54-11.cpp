class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        vector<int> v(n+1);
        v[0]=1;
        v[1]=s[0] == '0' ? 0:1 ; //for now;
        
        for(int i=2; i<=n; i++){
            int od = s[i-1]-'0';
            int td = 10*(s[i-2]-'0')+s[i-1]-'0';
            cout<<od<< " "<<td;
            if(od>=1) v[i]+=v[i-1];
            if(td>=10 and td<=26) v[i]+=v[i-2];
        }
        return v[n];
    }
};
