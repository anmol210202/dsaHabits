class Solution {
public:
    bool halvesAreAlike(string s) {
        char x[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int i=0 , size = s.size() , f1 = 0 , f2=0;
        while(i<size/2){
            for(auto &e : x){
                if(e==s[i]){
                    f1++;
                }
                if(e == s[i+size/2]){
                    f2++;
                }
            }
            i++;
        }
        if(f1==f2) return true;
        else return false;
    }
};
