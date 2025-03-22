class Solution {
public:
    // Maximum n is 50; we use a fixed-size array with a little extra space.
    static const int MAXN = 55;
    int parent[MAXN], compSize[MAXN], compEdges[MAXN];
    bool vis[MAXN];

    // Inline find function with path halving; force inlining.
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
        if(rx == ry) return;
        if(compSize[rx] < compSize[ry]) {
            parent[rx] = ry;
            compSize[ry] += compSize[rx];
            compEdges[ry] += compEdges[rx];
        } else {
            parent[ry] = rx;
            compSize[rx] += compSize[ry];
            compEdges[rx] += compEdges[ry];
        }
    }
    
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // Initialize DSU arrays.
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            compSize[i] = 1;
            compEdges[i] = 0;
            vis[i] = false;
        }
        
        int m = edges.size();
        // Process every edge in a single pass.
        for (int i = 0; i < m; ++i) {
            int u = edges[i][0], v = edges[i][1];
            int ru = find(u), rv = find(v);
            if(ru == rv) {
                // Increment edge count if the edge is within the same component.
                compEdges[ru]++;
            } else {
                // Merge and then add the edge count.
                unionSet(ru, rv);
                compEdges[find(u)]++;
            }
        }
        
        int ans = 0;
        // Check each component exactly once.
        for (int i = 0; i < n; ++i) {
            int r = find(i);
            if (!vis[r]) {
                vis[r] = true;
                // For a complete component of size s, there must be exactly s*(s-1)/2 edges.
                if (compEdges[r] == compSize[r] * (compSize[r] - 1) / 2)
                    ans++;
            }
        }
        return ans;
    }
};

