class Solution {
public:
    string uttar;
    bool solve(string &pattern,string &ans,int index,vector<int>&visited){
         if(index>=pattern.length()){
             if(ans.length()==pattern.length()+1){
                 return true;
             }
             return false;
         }
         if(pattern[index]=='I'){
             int value=ans[index]-'0';
             for(int i=value+1;i<=9;i++){
                 if(!visited[i]){
                      visited[i]=1;
                      ans+=to_string(i);
                      if(solve(pattern,ans,index+1,visited)){
                          return true;
                      }
                      visited[i]=0;
                      ans.pop_back();
                 }
             }
         }
         else if(pattern[index]=='D'){
            int value=ans[index]-'0';
            for(int i=1;i<=value-1;i++){
                if(!visited[i]){
                    visited[i]=1;
                    ans+=to_string(i);
                    if(solve(pattern,ans,index+1,visited)){
                        return true;
                    }
                    visited[i]=0;
                    ans.pop_back();
                }
            }
         }
         return false;
    }
    string smallestNumber(string pattern) {
        vector<int>visited(10,0);
        string ans="";
        for(int i=1;i<=9;i++){
            ans+=to_string(i);
            visited[i]=1;
            if(solve(pattern,ans,0,visited)){
                return ans;
            }
            ans.pop_back();
            visited[i]=0;
        }
        return "";
    }
};