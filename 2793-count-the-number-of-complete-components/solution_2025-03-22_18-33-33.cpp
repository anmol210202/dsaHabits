class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // Build the adjacency list for the graph
        vector<vector<int>> graph(n);
        for (const auto &edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        vector<bool> visited(n, false);
        int completeComponents = 0;
        
        // Traverse each node to find connected components
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                vector<int> component;
                // Use BFS (you can also use DFS)
                queue<int> q;
                q.push(i);
                visited[i] = true;
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    component.push_back(node);
                    for (int neighbor : graph[node]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }
                
                // Calculate the number of edges in the component.
                int nodesCount = component.size();
                int edgeCount = 0;
                for (int node : component) {
                    edgeCount += graph[node].size();
                }
                edgeCount /= 2;  // each edge is counted twice
                
                // Check if the component is complete:
                // A complete graph with nodesCount nodes has nodesCount*(nodesCount-1)/2 edges.
                if (edgeCount == nodesCount * (nodesCount - 1) / 2)
                    completeComponents++;
            }
        }
        
        return completeComponents;
    }
};

