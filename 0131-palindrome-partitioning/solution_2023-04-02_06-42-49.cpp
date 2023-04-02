class Solution {
public:
    vector<string> tmp;
    vector<vector<string>> ans;
    bool c(string &s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            else i++,j--;
        }
        return true;
    }
    void r(string &s, int i){
        if(i==s.size()){
            ans.push_back(tmp);
            return ;
        }
        for(int j=i; j<s.size(); j++){
            if(c(s,i,j)){
                tmp.push_back(s.substr(i,j-i+1));
                r(s,j+1);
                tmp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        r(s,0);
        return ans;
    }
};
