class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> map;
        int startPoint = 0;
        string ans = "";
        for(auto c:t){
            map[c]++;
        }

        int l=0,r=0;
        int lenAns =INT_MAX, st=0 , ln=0;
        int mapSize = map.size();
        int formed = 0;
    
        unordered_map<char,int> windowCount;

        while(r<s.size()){
            char c = s[r];
            windowCount[c]++;
            if(map.find(c)!=map.end() && windowCount[c]==map[c]){
                formed++;
            }

            while(l<=r && formed==mapSize){
                char c=s[l];
                if(r-l+1 < lenAns){
                    st=l;
                    ln=r;
                    lenAns=r-l+1;
                }
                windowCount[c]--;
                if(map.find(c)!=map.end() && windowCount[c]<map[c]){
                    formed--;
                }
                l++;
            }

            r++;
        }
        cout<<st<<ln<<lenAns<<endl;
        return lenAns==INT_MAX ? "": s.substr(st,lenAns);
    }
};
