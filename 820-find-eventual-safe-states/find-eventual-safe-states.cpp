class Solution {
public:
 bool dfs(unordered_map<int,vector<int>>&mp,vector<int>&visited,vector<int>&dfsvisited,int source){
     visited[source]=true;
     dfsvisited[source]=true;
     for(auto i: mp[source]){
         cout<<i<<endl;
         if(!visited[i]){
             if (dfs(mp,visited,dfsvisited,i))
                  return true;
         }
         else if(visited[i]==true && dfsvisited[i]==true){
             return true;  
         }
     }
     dfsvisited[source]=false;
     return false;
 }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
          unordered_map<int,vector<int>> mp;
          for(int i=0;i<graph.size();i++){
              mp[i]=graph[i];
          }
           vector<int> visited(graph.size(),false);
          vector<int>dfsvisited(graph.size(),false);  
          vector<int>temp;
          for(int i=0;i<graph.size();i++){
         
              if(dfs(mp,visited,dfsvisited,i)==false){
                  temp.push_back(i);
              }
          }
          return temp;
    }
};