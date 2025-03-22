class Solution {
public:
    static const int N = 55;  // n <= 50, a few extras for safety
    int parent[N], sz[N], ed[N];

    // Force inline find with path halving.
    inline __attribute__((always_inline)) int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    // Force inline union by size, merging edge counts.
    inline __attribute__((always_inline)) void unionSet(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) {
            parent[a] = b;
            sz[b] += sz[a];
            ed[b] += ed[a];
        } else {
            parent[b] = a;
            sz[a] += sz[b];
            ed[a] += ed[b];
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // DSU initialization.
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            sz[i] = 1;
            ed[i] = 0;
        }
        // Process each edge.
        for (int i = 0, m = edges.size(); i < m; ++i) {
            int u = edges[i][0], v = edges[i][1];
            int ru = find(u), rv = find(v);
            if (ru == rv) {
                ed[ru]++;
            } else {
                unionSet(ru, rv);
                ed[find(u)]++;
            }
        }
        // Count components that are complete (edge count must equal sz*(sz-1)/2).
        int ans = 0;
        for (int i = 0; i < n; ++i)
            if (find(i) == i && ed[i] == sz[i] * (sz[i] - 1) / 2)
                ans++;
        return ans;
    }
};

