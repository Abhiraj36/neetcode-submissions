class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // A tree must have exactly n - 1 edges
        if (edges.size() != n - 1) return false;

        // Build adjacency list using hashmap
        unordered_map<int, vector<int>> graph;

        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        // BFS to check connectivity
        queue<int> q;
        vector<bool> visited(n, false);

        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int nei : graph[node]) {
                if (!visited[nei]) {
                    visited[nei] = true;
                    q.push(nei);
                }
            }
        }

        // Check if all nodes were visited
        for (bool v : visited) {
            if (!v) return false;
        }

        return true;
    }
};

