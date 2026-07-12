class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {

        // Build adjacency list using hashmap
        unordered_map<int, vector<int>> graph;
        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        int components = 0;

        // For each node, if not visited -> BFS that component
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                components++;  // found a new component

                // BFS from this node
                queue<int> q;
                q.push(i);
                visited[i] = true;

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
            }
        }

        return components;
    }
};

