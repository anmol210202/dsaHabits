class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> q;
        unordered_map<string,int> vis;
        int steps=0;
        q.push(start);
        vis[start]=1;
        while(!q.empty()){
            for(int i=q.size(); i>0; i--){
                auto sq=q.front(); q.pop();
                if(sq==end){
                    for (auto itr = vis.begin(); itr != vis.end(); ++itr) {
                       cout << '\t' << itr->first << '\t' << itr->second
                            << '\n';
                     }
                    cout << endl;
                    return steps;
                }
                for(int j=0; j<8; j++){
                    char temp = sq[j];
                    for(int k=0; k<4; k++){
                        sq[j]="ACGT"[k];
                        if(!vis[sq] and find(bank.begin(),bank.end(),sq)!=bank.end()){
                            q.push(sq);
                            vis[sq] = 1;
                        }
                    }
                    sq[j]=temp;
                }   
            }
            steps++;
        }
        return -1;
    }
};
