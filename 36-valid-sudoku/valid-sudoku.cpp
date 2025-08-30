class Solution {
public:
    bool issafe(vector<vector<char>>&board,int row,int col, int num){
        int count=0;
      for(int i=0;i<board.size();i++){

          if((board[row][i])==static_cast<char>(num+'0')){
              count++;
           
          }
          if(count>1){
              return false;
          }
      }
      count=0;
      for(int i=0;i<board.size();i++){
          if(board[i][col]==static_cast<char>(num+'0')){
          count++;
          }
          if(count>1){
              return false;
          }
      }
        count=0;
        int number=sqrt(board.size());
        int x=row;
        int y=col;
        x=x-x%number;
        y=y-y%number;
        for(int i=x;i<x+number;i++){
            for(int j=y;j<y+number;j++){
                if(board[i][j]==static_cast<char>(num+'0')){
                   count++;
                }
                if(count>1){
                    return false;
                }
            }
        }
        return true;
    }
    bool isvalid(vector<vector<char>>&board){
     
        bool flag=false;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                 if(board[i][j]!='.'){
                     if(issafe(board,i,j,board[i][j]-'0')==false){
                           return false;
                     }
                 }
            }
           
            }
            return true;
            }
    bool isValidSudoku(vector<vector<char>>& board) {
        return isvalid(board);
        
    }
};