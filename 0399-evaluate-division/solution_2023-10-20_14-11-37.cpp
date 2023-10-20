class Solution {
public:
    unordered_map<string,unordered_map<string,double>> graph;

    double dfs(string A , string B , unordered_set<string> &visited){
        if(graph.find(A)==graph.end() || visited.count(A)) return -1.0;

        if(A==B) return 1.0;

        visited.insert(A);
        for(const auto& neighbor : graph[A]){
            double result = dfs(neighbor.first , B ,visited);
            if(result > 0){
                return result*neighbor.second;
            }
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        for(int i=0; i<n; i++){
            string A = equations[i][0];
            string B = equations[i][1];
            double val = values[i];
            graph[A][B] = val;
            graph[B][A] = 1.0/val;
        }

        vector<double> results;
        for(auto &e:queries){
            string A = e[0];
            string B = e[1];
            unordered_set<string> visited;
            double result = dfs(A,B,visited);
            if(result > 0){
                results.push_back(result);
            } else {
                results.push_back(-1.0);
            }
        }

        return results;
    }
};
