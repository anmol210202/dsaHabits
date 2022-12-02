class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int l1 = word1.size() , l2 = word2.size();
        if(l1!=l2) return false ;
        map<char,int> m1,m2;
        for(l1; l1>0; l1--){
            m1[word1[l2-l1]]++;
            m2[word2[l2-l1]]++;
        }
        vector<char> c,C;
        vector<int> i,I;
        for(auto &e:m1){
            c.push_back(e.first);
            i.push_back(e.second);
        }
        sort(i.begin(),i.end());
        for(auto &e:m2){
            C.push_back(e.first);
            I.push_back(e.second);
        }
        sort(I.begin(),I.end());
        if(c == C and i == I) return true;
        return false;
    }
};
