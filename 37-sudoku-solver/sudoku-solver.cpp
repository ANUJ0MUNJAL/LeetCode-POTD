class Solution {
public:
         bool issafe(vector<vector<char>>&board,int row,int col, int num){
    //   cout<<num<<endl;
      for(int i=0;i<board.size();i++){
        //   cout<<board[row][i]<<" ";
        //   cout<<(char)num+'0'<<endl;
          if((board[row][i])==static_cast<char>(num+'0')){
             
              return false;
          }
      }
      for(int i=0;i<board.size();i++){
          if(board[i][col]==static_cast<char>(num+'0')){
            //    cout<<num<<endl;
              return false;
          }
      }
        
        int number=sqrt(board.size());
        int x=row;
        int y=col;
        x=x-x%number;
        y=y-y%number;
        for(int i=x;i<x+number;i++){
            for(int j=y;j<y+number;j++){
                if(board[i][j]==static_cast<char>(num+'0')){
                    return false;
                }
            }
        }
        return true;
    }
    bool isvalid(vector<vector<char>>&board){
         int row=-1;
        int col=-1;
        bool flag=false;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    row=i;
                    col=j;
                    flag=true;
                    break;
                }
            }
                if(flag==true){
                    break;
                }

            }

            if(flag==false){
                return true;
            }
            
            for(int i=1;i<=9;i++){
                if(issafe(board,row,col,i)){
                    board[row][col]=i+'0';
                    if(isvalid(board)){
                        return true;
                    }else{
                        board[row][col]='.';
                    }
                    

                }
            }
            return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        bool ans=isvalid(board);

       
    }
};