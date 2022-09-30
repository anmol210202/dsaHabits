class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
      vector<int> v(s.size());
        for(int i=0; i<shifts.size(); i++){
            int x=shifts[i][0];
            int y=shifts[i][1];
            bool z=shifts[i][2];
            if(z){
                v[x]+=1;
                if(y!=s.size()-1) v[y+1]-=1;
            } else {
                v[x]-=1;
                if(y!=s.size()-1) v[y+1]+=1;
            }
        }
        for(int i=1; i<s.size(); i++){
            // cout<<v[i]<<' ';
            v[i]=v[i]+v[i-1];
        }
        for(int i=0; i<s.size(); i++){
            // s[i]+=((v[i]%26)-'a'+26)%26+'a';
            s[i]=(s[i]+(v[i]%26)-'a'+26)%26+'a';
        }
        return s;
        // for(int i=0; i<n; i++){
        //     int x=shifts[i][0];
        //     int y=shifts[i][1];
        //     bool z=shifts[i][2];
        //     for(int j=x; j<=y; j++){
        //         if(z){
        //             if(s[j]=='z') s[j]='a';
        //             else s[j]+=1;
        //         } else{
        //             if(s[j]=='a') s[j]='z';
        //             else s[j]-=1;
        //         }
        //     }
        // }
        // return s;
    }
};
