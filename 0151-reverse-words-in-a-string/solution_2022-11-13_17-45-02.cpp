class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string temp;
        for(auto &e:s){
            if(e!=' '){
                temp+=e;
            }
            else if(temp.size()!=0){
                words.push_back(temp);
                temp.clear();
            }
        }
        if(temp.size()!=0) words.push_back(temp);
        s.clear();
        for(int i=words.size()-1; i>=0; i--){
            s+=words[i];
            if(i!=0) s+=' ';
        }
        return s;
    }
};
