class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
      
        vector<vector<int>>visited(rows,vector<int>(cols,false));
        vector<vector<int>> ans;
        int r=rStart;
        int c=cStart;

        int right=1,down=1,left=2,up=2;
        ans.push_back({r,c});
        visited[r][c]=1;
        c++;
        while(true){
            
            for(int i=0;i<right;i++){
                   if(r < rows and c < cols and r >=0 and c >= 0){
                         visited[r][c]=1;
                         ans.push_back({r,c});
                   }
                   c++;
            }
            r++;
            c--;
            right+=2;

            for(int i=0;i<down;i++){
                   if(r < rows and c < cols and r >=0 and c >= 0){
                         visited[r][c]=1;
                         ans.push_back({r,c});
                   }
                   r++;
            }
            r--;
            c--;
            down+=2;
            for(int i=0;i<left;i++){
                  if(r < rows and c < cols and r >=0 and c >= 0){
                         visited[r][c]=1;
                         ans.push_back({r,c});
                   }
                   c--;
            }
            c++;
            r--;
            left+=2;
             for(int i=0;i<up;i++){
                  if(r < rows and c < cols and r >=0 and c >= 0){
                         visited[r][c]=1;
                         ans.push_back({r,c});
                   }
                   r--;
            }
            r++;
            c++;
            up+=2;
            
            if(visited[rows-1][cols-1] and visited[0][0] and visited[rows-1][0] and visited[0][cols-1])
            {
                return ans;
            }


        }
        return ans;

        
    }
};