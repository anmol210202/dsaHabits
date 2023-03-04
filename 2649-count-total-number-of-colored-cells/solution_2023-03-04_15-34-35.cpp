class Solution {
public:
    long long coloredCells(int n) {
        // vector<vector<int>> v(3*n+1,vector<int>(3*n+1));
        // v[n][n]=1;
        // while(n--){
        //     vector<vector<int>> tmp(v);
        //     for(auto i=0; i<3*n; i++){
        //         for(auto j=0; j<3*n; j++){
        //             if(v[i][j]==1) tmp[i-1][j]=1,tmp[i+1][j]=1,tmp[i][j-1]=1,tmp[i][j+1]=1;
        //         }
        //     }
        //     v=tmp;
        // }
        // long long c=0;
        // for(auto &E:v) for(auto &e:E) if(e==1) c++;
        // return c;
        // vector<vector<int>> grid(3*n+1, vector<int>(3*n+1));
        // grid[n][n] = 1; // color the center cell blue
        // for (int k = 1; k < n; k++) {
        //     vector<vector<int>> new_grid(grid);
        //     for (int i = 1; i < 3*n; i++) {
        //         for (int j = 1; j < 3*n; j++) {
        //             if (grid[i][j] == 1) {
        //                 new_grid[i-1][j] = 1;
        //                 new_grid[i+1][j] = 1;
        //                 new_grid[i][j-1] = 1;
        //                 new_grid[i][j+1] = 1;
        //             }
        //         }
        //     }
        //     grid = new_grid;
        // }
        // int count = 0;
        // for (int i = 0; i < 3*n+1; i++) {
        //     for (int j = 0; j < 3*n+1; j++) {
        //         if (grid[i][j] == 1) {
        //             count++;
        //         }
        //     }
        // }
        // return count;
        // unordered_set<int> blues;
        // blues.insert(0); // add the center cell
        // for (int k = 1; k < n; k++) {
        //     unordered_set<int> new_blues;
        //     for (int b : blues) {
        //         int i = b / 1000, j = b % 1000;
        //         new_blues.insert((i-1)*1000 + j);
        //         new_blues.insert((i+1)*1000 + j);
        //         new_blues.insert(i*1000 + j-1);
        //         new_blues.insert(i*1000 + j+1);
        //     }
        //     blues = new_blues;
        // }
        // return  blues.size();
    //         vector<vector<bool>> grid(2*n+1, vector<bool>(2*n+1, false));
    // grid[n][n] = true; // color the center cell blue
    // queue<pair<int,int>> q;
    // q.push({n,n});
    // long long count = 1;
    // for (int k = 1; k < n; k++) {
    //     int size = q.size();
    //     for (int i = 0; i < size; i++) {
    //         int x = q.front().first, y = q.front().second;
    //         q.pop();
    //         if (!grid[x-1][y]) {
    //             grid[x-1][y] = true;
    //             q.push({x-1,y});
    //             count++;
    //         }
    //         if (!grid[x+1][y]) {
    //             grid[x+1][y] = true;
    //             q.push({x+1,y});
    //             count++;
    //         }
    //         if (!grid[x][y-1]) {
    //             grid[x][y-1] = true;
    //             q.push({x,y-1});
    //             count++;
    //         }
    //         if (!grid[x][y+1]) {
    //             grid[x][y+1] = true;
    //             q.push({x,y+1});
    //             count++;
    //         }
    //     }
    // }
    //     return count;
        long long x=n-1;
        return 2*x*(x+1) + 1;
    }
};
