class Solution {
public:
    static const int N = 55; // n <= 50, with extra room.
    int p[N], sz[N], ed[N];

    // Inline find with path halving.
    inline __attribute__((always_inline)) int find(int x) {
        while (p[x] != x) {
            p[x] = p[p[x]];
            x = p[x];
        }
        return x;
    }

    // Inline union by size; merge and update edge counts.
    inline __attribute__((always_inline)) void unionSet(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) {
            p[a] = b;
            sz[b] += sz[a];
            ed[b] += ed[a];
        } else {
            p[b] = a;
            sz[a] += sz[b];
            ed[a] += ed[b];
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // Initialize DSU arrays.
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            sz[i] = 1;
            ed[i] = 0;
        }
        
        int m = edges.size();
        // Process each edge.
        for (int i = 0; i < m; ++i) {
            int u = edges[i][0], v = edges[i][1];
            int ru = find(u), rv = find(v);
            if (ru == rv) {
                ed[ru]++;
            } else {
                unionSet(ru, rv);
                ed[find(u)]++;
            }
        }
        
        // Count complete components: only check the roots.
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (find(i) == i) {
                int s = sz[i];
                if (ed[i] == s * (s - 1) / 2)
                    ans++;
            }
        }
        return ans;
    }
};

