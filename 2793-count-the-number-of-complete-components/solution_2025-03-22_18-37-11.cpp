class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n), size(n, 1), edgeCount(n, 0);
        iota(parent.begin(), parent.end(), 0);
        
        // Find with path compression.
        function<int(int)> find = [&](int x) -> int {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        };
        
        // Union by size, merging edge counts as well.
        auto unionSet = [&](int a, int b) -> int {
            a = find(a), b = find(b);
            if (a == b)
                return a;
            if (size[a] < size[b]) 
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            edgeCount[a] += edgeCount[b];
            return a;
        };
        
        // Process each edge.
        for (const auto &edge : edges) {
            int u = edge[0], v = edge[1];
            int ru = find(u), rv = find(v);
            if (ru == rv) {
                // The edge is within the same component.
                edgeCount[ru]++;
            } else {
                // Merge the two components and count the edge.
                int newRoot = unionSet(ru, rv);
                edgeCount[newRoot]++;
            }
        }
        
        // Count complete components.
        // A component with m nodes must have m*(m-1)/2 edges to be complete.
        vector<bool> visited(n, false);
        int completeComponents = 0;
        for (int i = 0; i < n; i++) {
            int root = find(i);
            if (!visited[root]) {
                visited[root] = true;
                int m = size[root];
                // For an isolated vertex, m = 1 and expected edge count is 0.
                if (edgeCount[root] == m * (m - 1) / 2)
                    completeComponents++;
            }
        }
        return completeComponents;
    }
};

