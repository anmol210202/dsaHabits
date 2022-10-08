class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> v(numRows,""); 
            int g=0;
        string ans="";
        int size=s.length();
        if(numRows==1) return s;
        for(int i=0; i<numRows; i++){
            for(int j=0; j<size; j++){
                if(i==0){
                    int x=2*numRows-2;
                    if(j%x==0){
                         v[i]+=s[j];
                    }
                }
                if(i==numRows-1){
                    int x=2*numRows-2;
                    int y=j-i;
                    if((y)%x==0){
                         v[i]+=s[j];
                    }
                }
                if(i!=0 and i!=numRows-1){
                    int x=2*numRows-2;
                    int y=j-i;
                    // if(j%(i+(numRows-0))==0 and j!=0){
                    //      v[i]+=s[j];
                    //     g+=2;
                    // }
                    if((y)%x==0){
                         v[i]+=s[j];
                        
                    }
                    int check=0;
                    // if((j+1)%(2*(numRows-1))==0 and j!=0 ) {
                    //     v[i]+=s[j-i+1];
                    // }
                     if((j+1+numRows-2)%(2*(numRows-1))==0 and j!=0 and (j-i+1+numRows-2)<size) {
                         char f1 = s[j-i+1+numRows-2];
                         // cout<<int(f1)<<endl;
                         if(f1!=0) v[i]+=s[j-i+1+numRows-2];
                    }
                }
            }
            ans+=v[i];
            cout<<v[i]<<endl;
        }
        return ans;
    }
};
