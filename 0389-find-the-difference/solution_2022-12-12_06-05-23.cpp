class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char,int> m;
        for(auto &e:t) m[e]++;
        for(auto &e:s) m[e]--;
        for(auto &e:m){
            if(e.second==1){
                return e.first;
                break;
            }
        }
        return 'a';
    }
};
