class Solution {
public:
    string reverseWords(string s) {
        stringstream S(s);
        string word;
        s.clear();
        while(S>>word){
            reverse(word.begin(),word.end());
            s+=word+' ';
        }
        s.pop_back();
        return s;
    }
};
