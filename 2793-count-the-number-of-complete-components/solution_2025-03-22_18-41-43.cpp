class Solution {
public:
    // Maximum n is 50; we use a slightly larger fixed array.
    int parent[55], compSize[55], compEdges[55];
    bool visited[55];
    
    // Inline iterative find with path halving.
    inline int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]]; // path halving
            x = parent[x];
        }
        return x;
    }
    
    // Inline union by size that merges edge counts.
    inline void unionSet(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return;
        // Always merge smaller component into larger one.
        if (compSize[rx] < compSize[ry]) {
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
            visited[i] = false;
        }
        
        // Process each edge.
        int m = edges.size();
        for (int i = 0; i < m; ++i) {
            int u = edges[i][0], v = edges[i][1];
            int ru = find(u), rv = find(v);
            if (ru == rv) {
                // Edge within the same component.
                compEdges[ru]++;
            } else {
                // Merge the components then count the edge.
                unionSet(ru, rv);
                // After union, add the current edge to the new root.
                compEdges[find(u)]++;
            }
        }
        
        // Count complete components.
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int r = find(i);
            if (!visited[r]) {
                visited[r] = true;
                int s = compSize[r];
                // A complete graph with s nodes must have s*(s-1)/2 edges.
                if (compEdges[r] == s * (s - 1) / 2)
                    ans++;
            }
        }
        return ans;
    }
};

