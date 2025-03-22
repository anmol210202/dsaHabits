class Solution {
public:
    // Use fixed-size arrays given the problem constraints.
    int parent[55], compSize[55], compEdges[55];
    bool visited[55];

    // Force inline the find routine (using GCC/Clang attribute, remove if not supported).
    inline __attribute__((always_inline)) int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]]; // Path halving
            x = parent[x];
        }
        return x;
    }
    
    // Force inline the union routine.
    inline __attribute__((always_inline)) void unionSet(int x, int y) {
        int rx = find(x), ry = find(y);
        if(rx == ry) return;
        // Always merge the smaller component into the larger one.
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
        // Initialization using fixed-size arrays.
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            compSize[i] = 1;
            compEdges[i] = 0;
            visited[i] = false;
        }
        
        int m = edges.size();
        for (int i = 0; i < m; ++i) {
            int u = edges[i][0], v = edges[i][1];
            int ru = find(u), rv = find(v);
            if(ru == rv) {
                // Edge within the same component.
                compEdges[ru]++;
            } else {
                // Merge the two components and then add the current edge.
                unionSet(ru, rv);
                compEdges[find(u)]++;
            }
        }
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int r = find(i);
            if (!visited[r]) {
                visited[r] = true;
                int s = compSize[r];
                // Check for complete component: expected edges for s nodes is s*(s-1)/2.
                if (compEdges[r] == s * (s - 1) / 2)
                    ans++;
            }
        }
        return ans;
    }
};

