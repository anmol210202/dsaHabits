class Solution {
public:
    int partitionString(string s) {
        vector<bool> vb(26,false);
        int c=1;
        for(auto &e:s){
            if(vb[e-'a']){
                fill(vb.begin(),vb.end(),false);
                c++;
                vb[e-'a']=true;
            }
            else{
                vb[e-'a']=true;
            }
        }
        return c;
    }
};
