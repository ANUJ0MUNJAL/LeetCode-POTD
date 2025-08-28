class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        map<int,multiset<int>> mp;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                mp[(i-j)].insert(grid[i][j]);
            }
        }
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(i >= j)
                {
                    auto itr = mp[(i-j)].end();
                    itr--;
                    grid[i][j] = *itr;
                    mp[(i-j)].erase(itr);
                }else{
                    grid[i][j] = *mp[(i-j)].begin();
                    mp[(i-j)].erase(mp[(i-j)].begin());
                }
            }
        }
        return grid;
    }
};