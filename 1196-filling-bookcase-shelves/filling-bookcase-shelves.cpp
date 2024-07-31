class Solution {
public:
    long long dp[1001];
    int solve(vector<vector<int>>&books,int index,int width,int shelfWidth){
        if(index >=books.size())return 0;
        if(dp[index]!=-1)return dp[index];
         int maxi=0;
         int mini=INT_MAX;
         for(int i=index;i<books.size();i++){
                 maxi=max(maxi,books[i][1]);
                 width-=books[i][0];
                 if(width < 0){
                      break;
                 }else{
                      mini=min(mini,maxi+solve(books,i+1,shelfWidth,shelfWidth));
                 }
                  
         }
         return dp[index]=mini;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
             memset(dp,-1,sizeof(dp));
             return solve(books,0,shelfWidth,shelfWidth);
    }
};