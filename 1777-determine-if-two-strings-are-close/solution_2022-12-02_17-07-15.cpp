class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int l1 = word1.size() , l2 = word2.size();
        if(l1!=l2) return false;
        set<char> s1,s2;
        vector<int> v1(26,0) , v2(26,0);
        for(int i=0; i<l1; i++){
            s1.insert(word1[i]);
            s2.insert(word2[i]);
            v1[word1[i]-'a']++;
            v2[word2[i]-'a']++;
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        if(s1==s2 and v1==v2) return true;
        return false;
    }
};
