class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        vector<int> v(100000,0),vec;
        for(auto &e:banned) v[e]=1;
        for(int i=1; i<=n; i++) if(v[i]==0) vec.push_back(i);
        // cout<<vec[vec.size()-1]<<endl;
        // for(auto &e:vec) cout<<e<<' ';
        // unordered_set<int> s;
        // int i=0,j=vec.size()-1;
        int sum=0,c=0;;
        for(auto &e:vec){
            if(sum+e<=maxSum) sum+=e,c++;
            else break;
        }
        return c;
    }
};
