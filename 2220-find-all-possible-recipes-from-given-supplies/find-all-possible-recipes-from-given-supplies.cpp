class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
          map<string,vector<string>> mp;
          map<string,int> indegree;
          set<string> st(supplies.begin(),supplies.end());
          set<string> ans(recipes.begin(),recipes.end());
    
        
          for(int i=0;i<ingredients.size();i++)
          {
              int count = 0;
              for(auto j: ingredients[i])
              {
                  
                      mp[j].push_back(recipes[i]);
                      indegree[recipes[i]]++;
                   
              }
       
            
          }
          vector<string> answer;
          queue<string> q;
          for(auto j: supplies)q.push(j);


          while(!q.empty())
          {
              auto el = q.front();
              q.pop();

              


              for(auto &neigh: mp[el])
              {
                   indegree[neigh]--;
                   if(indegree[neigh] == 0)
                   {
                      
                      q.push(neigh);
                      if(ans.find(neigh)!=ans.end())
                      {
                           answer.push_back(neigh);
                      }
                   }
              }
          }

          return answer;

          

        
    }
};