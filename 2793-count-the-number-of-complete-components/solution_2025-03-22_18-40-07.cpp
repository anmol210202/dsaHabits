class Solution {
public:
    // Since n <= 50, we can use fixed-size arrays.
    int parent[55], compSize[55], compEdges[55];
    
    // Iterative find with path halving.
    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    
    // Union by size (compSize) and merge edge counts.
    void unionSet(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry)
            return;
        // Ensure rx is the larger component.
        if (compSize[rx] < compSize[ry]) {
            swap(rx, ry);
        }
        parent[ry] = rx;
        compSize[rx] += compSize[ry];
        compEdges[rx] += compEdges[ry];
    }
    
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // Initialize DSU structures.
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            compSize[i] = 1;
            compEdges[i] = 0;
        }
        
        // Process each edge.
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0], v = edges[i][1];
            int ru = find(u), rv = find(v);
            if (ru == rv) {
                // Edge within the same component.
                compEdges[ru]++;
            } else {
                // Merge the two components and then add the edge.
                unionSet(ru, rv);
                int rnew = find(u);
                compEdges[rnew]++;
            }
        }
        
        // Mark visited roots and count complete components.
        bool visited[55] = { false };
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int r = find(i);
            if (!visited[r]) {
                visited[r] = true;
                int m = compSize[r];
                // A complete graph with m nodes has m*(m-1)/2 edges.
                if (compEdges[r] == m * (m - 1) / 2)
                    ans++;
            }
        }
        return ans;
    }
};

