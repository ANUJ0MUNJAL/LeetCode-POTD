class Solution {
public:
    set<vector<int>> st;
    bool solve(int n,int index,vector<int>&arr,vector<int>&visited)
    {
        if(index >= arr.size())
        {
            
            return true;
        }
        if(arr[index] != -1)
        {
            return solve(n,index+1,arr,visited);
        
        }
         
        for(int i=n;i>=1;i--)
        {
            
            if(!visited[i])
            {
                 if(i == 1)
                 {
                      arr[index]=i;
                      visited[i]=1;
                    if(solve(n,index+1,arr,visited))return true;
                      arr[index]=-1;
                      visited[i]=0;
                 }
               else if(index+i < arr.size() and arr[index+i] == -1)
                 {
                      arr[index]=i;  
                      arr[index+i]=i;
                      visited[i]=1;
                      if(solve(n,index+1,arr,visited))return true;
                      arr[index]=-1;
                      arr[index+i]=-1;
                      visited[i]=0;
                 }
            }
        }
        return false;
        
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int> arr(2*n-1,-1);
        vector<int> visited(n+1,false);
        solve(n,0,arr,visited);
       
        return arr;
    }
};