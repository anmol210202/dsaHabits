class Solution {
public:

    bool check(unordered_map<string,int> um , int word_len  , string subs){
        for(int i=0; i<subs.size(); i+=word_len){
            string temp = subs.substr(i,word_len);
            if(um.find(temp) != um.end()) {
                if(--um[temp]<0) return false;
            } else return false;
        }
        return true;
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        int word_len= words[0].size();
        int num_words = words.size();
        int stgLen = word_len*num_words;
        int n=s.size();

        unordered_map<string,int> um;

        for(auto &e:words) um[e]++;

        int i=0;

        vector<int> ans;

        while(i+stgLen<=n){
            if(check(um , word_len , s.substr(i,stgLen))){
                ans.push_back(i);
            }
            i++;
        }

        return ans;
    }
};
