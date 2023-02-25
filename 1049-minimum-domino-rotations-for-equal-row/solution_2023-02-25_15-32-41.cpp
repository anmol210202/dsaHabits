class Solution {
public:
    int minDominoRotations(vector<int>& t, vector<int>& b) {
        int n=t.size(),ans=-1;
        for(int i=1; i<7; i++){
            for(int j=0; j<n; j++){
                if(t[j]!=i and b[j]!=i){
                    ans=-1;
                    break;
                }
                else ans=i;
            }
            if(ans!=-1) break;
        }
        if(ans==-1) return -1;
        int x=0,y=0;
        for(int i=0; i<n; i++){
            if(t[i]==ans) x++;
            if(b[i]==ans) y++;
            if(t[i]==ans and b[i]==ans) x--,y--;
        }
        return min(x,y);
    }
};
