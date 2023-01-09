class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int t1[9][9]={0} , t2[9][9]={0} , t3[9][9]={0};
        for(int i=0; i<9; i++)
            for(int j=0;j<9;j++)
                if(board[i][j]!='.'){
                    int n = board[i][j]-'0' -1 , k=i/3*3+j/3;
                    if(t1[i][n] || t2[j][n] || t3[k][n]) return false;
                    t1[i][n]=t2[j][n]=t3[k][n]=1;
                }
        return true;
    }
};
