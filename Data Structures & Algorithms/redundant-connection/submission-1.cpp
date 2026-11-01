class Solution {
public:
    void dfs(vector<unordered_set<int>>& adj, vector<bool>& visited, int node) {
        for(auto i : adj[node]) {
            if(visited[i] == true)
                continue;
            
            visited[i] = true;
            dfs(adj,visited,i);
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<unordered_set<int>> adj(n+1);
        for(int i = 0; i < n; i++) {
            adj[edges[i][0]].insert(edges[i][1]);
            adj[edges[i][1]].insert(edges[i][0]);
        }

        for(int i = n-1; i >= 0; i--) {
            adj[edges[i][0]].erase(edges[i][1]);
            adj[edges[i][1]].erase(edges[i][0]);
            vector<bool> visited(n+1,false);
            dfs(adj,visited,i);
            
            bool stillConnect = true;
            for(int j = 1; j < n+1; j++) {
                if(visited[j] == false) {
                    stillConnect = false;
                    break;
                }
            }
            if(stillConnect)
                return edges[i];
            
            adj[edges[i][0]].insert(edges[i][1]);
            adj[edges[i][1]].insert(edges[i][0]);
        }
        
        return {};
    }
};
