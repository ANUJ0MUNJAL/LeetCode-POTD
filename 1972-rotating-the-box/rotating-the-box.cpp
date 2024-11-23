class Solution {
public:
    void solve(vector<vector<char>>&arr,vector<vector<char>>&box,int col,int row,int count)
    {
        
        if(row < arr.size())
         arr[row][col]='*';
         for(int i = row-1;i>=0 and count > 0;i--)
         {
              
              arr[i][col]='#';
              count--;
         }

    }
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
          vector<vector<char>> arr(box[0].size(),vector<char>(box.size(),'.'));
          for(int i=0;i<box.size();i++)
          {
             int count=0;
             for(int j=0;j<box[i].size();j++)
             {
                 if(box[i][j] == '#')
                 {
                     count++;
                 }
                 if(box[i][j] == '*')
                 {
                      solve(arr,box,box.size()-i-1,j,count);
                      count=0;
                 }
             }
             
             solve(arr,box,box.size()-i-1,box[0].size(),count);
          }
          return arr;
    }
};