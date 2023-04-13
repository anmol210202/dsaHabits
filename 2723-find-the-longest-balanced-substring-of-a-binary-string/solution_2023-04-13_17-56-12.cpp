class Solution {
public:
 int findTheLongestBalancedSubstring(std::string s) {
     stack<char> sta;
     int c=0,mx=0;
     bool tmp=false;
     for(auto &e:s){
         if(e=='1'){
             if(sta.empty()){
                 sta.push(e);
                 continue;
             }
             auto x= sta.top();
             if(x=='0') {
                 c+=2;
                 sta.pop();
             } else {
                 c=0;
                 sta.push(e);
             }
             mx=max(mx,c);
             tmp=true;
         }
         else{
             c=0;
             if(tmp){
                 while (!sta.empty()) {
                     sta.pop();
                 }
                 tmp=false;
             }
             sta.push(e);
         }
     }
     return mx;
    }
};
