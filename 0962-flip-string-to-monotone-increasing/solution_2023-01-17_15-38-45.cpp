class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int o=0, z=0;
        for(auto &e:s)
        if(e=='1') o++;
        else{z++; z=min(z,o);}
        return z;
    }
};
