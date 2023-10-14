class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;

        int m = board.size() , n = board[0].size() ; 

        //1st
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){ 
                if((i==0 or j==0 or i==m-1 or j==n-1) and board[i][j]=='O'){
                    dfs(board,i,j);
                }
            }
        }

        // 2nd

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){ 
                if(board[i][j]=='Y') board[i][j]='O';
                else if(board[i][j]=='O') board[i][j]='X';
            }
        }
    }

    void dfs(vector<vector<char>>& board , int i , int j){
        int m = board.size() , n = board[0].size() ; 
        if(i<0 or j<0 or i>=m or j>=n or board[i][j]!='O') return ;

        board[i][j]='Y';

        dfs(board,i+1,j);
        dfs(board,i-1,j);
        dfs(board,i,j+1);
        dfs(board,i,j-1);
    }
};
