class Solution {
public:
    bool issafe(int i,int j,int row,int col,vector<vector<bool>>&visited){
        if(i>=0 && j>=0 && i<row && j<col && visited[i][j]==false){
            visited[i][j]=1;
            return true;
        }
        return false;
    }
    bool ispossible(int row,int col,vector<vector<int>>&cells,int mid){
        vector<vector<bool>> visited(row,vector<bool>(col,false));
        // cout<<mid<<endl;
        for(int i=0;i<=mid;i++){
            
            int u=cells[i][0];
            int v=cells[i][1];
            // cout<<u<<" "<<v<<endl;
            visited[u-1][v-1]=1;
        }
          
        queue<pair<int,int>> q;
        for(int i=0;i<col;i++){
            if(visited[0][i]==0){
                q.push(make_pair(0,i));
                visited[0][i]=1;
            }
        }
      
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto element=q.front();
                int i=element.first;
                int j=element.second;
                q.pop();
                // visited[i][j]=1;
                if(i==row-1)
                    return true;

                if(issafe(i+1,j,row,col,visited)){
                    q.push(make_pair(i+1,j));
                }
                 if(issafe(i-1,j,row,col,visited)){
                    q.push(make_pair(i-1,j));
                }
                 if(issafe(i,j+1,row,col,visited)){
                    q.push(make_pair(i,j+1));
                }
                 if(issafe(i,j-1,row,col,visited)){
                    q.push(make_pair(i,j-1));
                }
            }
        }
        return false;

    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left=0;
        int right=cells.size()-1;
        int mid=left+(right-left)/2;
        int ans=-1;
        while(left<=right){
            // cout<<mid<<endl;
            if(ispossible(row,col,cells,mid)){
                ans=mid;
                left=mid+1;
            }
            else{
                
                right=mid-1;
            }
            mid=left+(right-left)/2;
        }
        return ans+1;
    }
};