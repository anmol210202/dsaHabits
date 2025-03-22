class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // Union-Find initialization.
        vector<int> parent(n), rank(n, 0);
        iota(parent.begin(), parent.end(), 0);
        
        // Define the find function with path compression.
        function<int(int)> find = [&](int x) -> int {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        };
        
        // Define the union function with union by rank.
        auto unionSet = [&](int x, int y) {
            int rootX = find(x), rootY = find(y);
            if (rootX == rootY)
                return;
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        };
        
        // Group vertices using the union operation for every edge.
        for (const auto &edge : edges) {
            unionSet(edge[0], edge[1]);
        }
        
        // Count the number of nodes in each component.
        unordered_map<int, int> compSize;
        for (int i = 0; i < n; i++) {
            int root = find(i);
            compSize[root]++;
        }
        
        // Count the edges in each component.
        unordered_map<int, int> compEdges;
        for (const auto &edge : edges) {
            int root = find(edge[0]);
            compEdges[root]++;
        }
        
        // Count complete components.
        int completeComponents = 0;
        for (const auto &p : compSize) {
            int root = p.first;
            int size = p.second;
            int expectedEdges = size * (size - 1) / 2;
            int actualEdges = compEdges[root];  // This will be 0 if the component has no edges (i.e. single vertex)
            if (actualEdges == expectedEdges)
                completeComponents++;
        }
        
        return completeComponents;
    }
};

