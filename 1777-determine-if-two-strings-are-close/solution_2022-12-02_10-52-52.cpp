class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int l1 = word1.size() , l2 = word2.size();
        if(l1!=l2) return false ;
        unordered_map<char,int> m1,m2;
        for(auto &e : word1){
            m1[e]++;
        }
        for(auto &e : word2){
            m2[e]++;
        }
        vector<char> c,C;
        vector<int> i,I;
        for(auto &e:m1){
            c.push_back(e.first);
            i.push_back(e.second);
        }
        sort(c.begin(),c.end());
        sort(i.begin(),i.end());
        for(auto &e:m2){
            C.push_back(e.first);
            I.push_back(e.second);
        }
        sort(C.begin(),C.end());
        sort(I.begin(),I.end());
        if(c == C and i == I) return true;
        return false;
    }
};
