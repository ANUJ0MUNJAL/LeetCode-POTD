class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        queue<int> q;
        map<int,vector<int>> mp;
        vector<int> indegree(numCourses,0);
        for(int i=0;i<prerequisites.size();i++)
        {
             mp[prerequisites[i][0]].push_back(prerequisites[i][1]);
             indegree[prerequisites[i][1]]++;
        }
        for(int i=0;i<indegree.size();i++)
        {
             if(indegree[i] == 0)q.push(i);
        }
        vector<vector<int>> vis(numCourses,vector<int>(numCourses,false));
        while(!q.empty())
        {
              auto el=q.front();
              q.pop();

              for(auto neigh: mp[el])
              {
                    vis[el][neigh]=1;
                    for(int i=0;i<numCourses;i++)
                    {
                         if(vis[i][el])vis[i][neigh]=1;
                    }
                    indegree[neigh]--;
                    if(indegree[neigh]==0)q.push(neigh);
              }
        }
          vector<bool> ans;
        for(int i=0;i<queries.size();i++)
        {
             if(vis[queries[i][0]][queries[i][1]])ans.push_back(true);
             else ans.push_back(false);
        }
        return ans;

    }
};