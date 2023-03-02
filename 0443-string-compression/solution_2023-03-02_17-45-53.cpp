class Solution {
public:
    int compress(vector<char>& c) {
        vector<pair<char,int>> vp;
        int i=0, j=0,s=c.size();
        while(i<s and j<s){
            if(c[i]==c[j]) j++;
            else{
                vp.push_back(make_pair(c[i],j-i));
                i=j;
            }
        }
        if(i<s and j==s) vp.push_back(make_pair(c[i],j-i));
        c.clear();
        int count=0;
        for(auto &e:vp){
            c.push_back(e.first);
            count++;
            if(e.second!=1){
                string tmp = to_string(e.second);
                for(auto &x:tmp) c.push_back(x),count++;
            }
        }
        return count;
    }
};
