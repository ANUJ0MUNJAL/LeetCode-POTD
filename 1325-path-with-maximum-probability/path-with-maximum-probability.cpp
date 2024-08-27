class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
       unordered_map<int,vector<pair<int,double>>> mp;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
              mp[u].push_back(make_pair(v,succProb[i]));
              mp[v].push_back(make_pair(u,succProb[i]));
        }
        vector<int>visited(n,0);
        vector<double>distance(n,0);
        priority_queue<pair<double,int>> pq;
        pq.push(make_pair(0,start));
        visited[start]=1;
        distance[start]=1;
        while(!pq.empty()){
            auto element=pq.top();
            double weight=element.first;
            int source=element.second;
            pq.pop();
            for(auto neighbour: mp[source]){
               
            
                if(distance[source]*neighbour.second>distance[neighbour.first]){

                          distance[neighbour.first]=distance[source]*neighbour.second;
                          pq.push(make_pair(distance[neighbour.first],neighbour.first));
                }
                
                 
            }

        }
        return distance[end];


    }
};