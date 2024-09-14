class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        set<pair<int,int>> st;
        for(auto j: queens)
        {
            st.insert({j[0],j[1]});
        }
        vector<vector<int>> ans;
        int row=king[0];
        int col=king[1];

        for(int i=col;i<8;i++)
        {
            if(st.find({row,i})!=st.end())
            {
                ans.push_back({row,i});
                break;
            }
        }
        for(int i=col;i>=0;i--)
        {
             if(st.find({row,i})!=st.end())
             {
                ans.push_back({row,i});
                break;
             }
        }

        for(int i=row;i<8;i++)
        {
             if(st.find({i,col})!=st.end())
             {
                ans.push_back({i,col});
                break;
             }
        }
        for(int i=row;i>=0;i--)
        {
             if(st.find({i,col})!=st.end())
             {
                ans.push_back({i,col});
                break;
             }
        }

        for(int i=row,j=col;i<8 && j<8 ;i++,j++)
        {
              if(st.find({i,j})!=st.end())
              {
                ans.push_back({i,j});
                break;
              }
        }
        for(int i=row,j=col;i>=0 and j < 8 ;i--,j++)
        {
             if(st.find({i,j})!=st.end())
             {
                ans.push_back({i,j});
                break;
             }
        }
          for(int i=row,j=col;i>=0 and j >=0 ;i--,j--)
        {
             if(st.find({i,j})!=st.end())
             {
                ans.push_back({i,j});
                break;
             }
        }
          for(int i=row,j=col;i<8 and j >=0 ;i++,j--)
        {
             if(st.find({i,j})!=st.end())
             {
                ans.push_back({i,j});
                break;
             }
        }
        return ans;

      
    }
};