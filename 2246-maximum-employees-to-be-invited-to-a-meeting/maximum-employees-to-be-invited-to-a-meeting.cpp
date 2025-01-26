class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
      vector<int> indegree(favorite.size(),0);
      vector<int> depth(favorite.size(),1);

      for(int i=0;i<favorite.size();i++)
      {
           indegree[favorite[i]]++;
      }
     
      queue<int> q;
      for(int i=0;i<favorite.size();i++)
      {
          if(indegree[i] == 0)q.push(i);
      }
      int ans = 0;
      int two=0;
      while(!q.empty())
      {
          int node = q.front();
          q.pop();
          
          int fr = favorite[node];
          depth[fr]=max(depth[fr],depth[node]+1);
          if(--indegree[fr] == 0)q.push(fr);
      }
     
      for(int i=0;i<favorite.size();i++)
      {
          if(indegree[i] == 0)continue;
          int len = 0;
          int temp = i;
          while(indegree[temp] != 0)
          {
               len++;
               indegree[temp]=0;
               temp = favorite[temp];
          }
      
          if(len == 2)
          {
             two+=depth[i]+depth[favorite[i]];
          }else{
              ans = max(ans,len);
          }


      }
      return max(ans,two);

    }
};