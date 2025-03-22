class Solution {
public:
    static const int MAXN = 55;
    int parent[MAXN], sizeArr[MAXN], edgesArr[MAXN];
    
    // Inline find function with path halving.
    inline __attribute__((always_inline)) int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    
    // Inline union function that merges by size and aggregates edge counts.
    inline __attribute__((always_inline)) void unionSet(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return;
        if (sizeArr[rx] < sizeArr[ry]) {
            parent[rx] = ry;
            sizeArr[ry] += sizeArr[rx];
            edgesArr[ry] += edgesArr[rx];
        } else {
            parent[ry] = rx;
            sizeArr[rx] += sizeArr[ry];
            edgesArr[rx] += edgesArr[ry];
        }
    }
    
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // DSU initialization.
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            sizeArr[i] = 1;
            edgesArr[i] = 0;
        }
        
        int m = edges.size();
        // Process each edge.
        for (int i = 0; i < m; ++i) {
            int u = edges[i][0], v = edges[i][1];
            int ru = find(u), rv = find(v);
            if (ru == rv) {
                edgesArr[ru]++;
            } else {
                unionSet(ru, rv);
                edgesArr[find(u)]++;
            }
        }
        
        // Final path compression.
        for (int i = 0; i < n; ++i)
            find(i);
        
        int ans = 0;
        // Instead of a visited array, we check for components by verifying if the node is its own parent.
        for (int i = 0; i < n; ++i) {
            if (parent[i] == i) {
                int s = sizeArr[i];
                if (edgesArr[i] == s * (s - 1) / 2)
                    ans++;
            }
        }
        return ans;
    }
};

