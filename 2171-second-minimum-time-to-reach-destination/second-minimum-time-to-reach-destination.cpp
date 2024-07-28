class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> graph(n); 
        for (auto& edge : edges) {
            graph[edge[0]-1].push_back(edge[1]-1); 
            graph[edge[1]-1].push_back(edge[0]-1); 
        }
        
        int least = -1; 
        queue<pair<int, int>> pq;
        pq.emplace(0, 0); 
        vector<vector<int>> seen(n); 
        
        while (pq.size()) {
            auto [t, u] = pq.front(); pq.pop(); 
            if (u == n-1) {
                if (least == -1) least = t; 
                else if (least < t) return t; 
            }
            if (t/change & 1) t = (t/change+1)*change; 
            t += time; 
            for (auto& v : graph[u]) 
                if (seen[v].empty() or (seen[v].size() == 1 and seen[v][0] != t)) {
                    seen[v].push_back(t); 
                    pq.emplace(t, v); 
                }
        }
        return -1; 

    }
};