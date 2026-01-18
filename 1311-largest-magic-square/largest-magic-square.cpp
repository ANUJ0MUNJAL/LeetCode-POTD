class Solution {
public:
    int ans = 1;

    void solve(int row, int col, vector<vector<int>>& grid)
    {
        for (int i = 1; i < 50; i++)
        {
            if (row + i < grid.size() && col + i < grid[0].size())
            {
                set<int> rowSet;
                set<int> colSet;

                for (int j = row; j <= row + i; j++)
                {
                    int sum = 0;
                    for (int k = col; k <= col + i; k++)
                    {
                        sum += grid[j][k];
                    }
                    rowSet.insert(sum);
                }
                if (rowSet.size() > 1) continue;

                for (int j = col; j <= col + i; j++)
                {
                    int sum = 0;
                    for (int k = row; k <= row + i; k++)
                    {
                        sum += grid[k][j];
                    }
                    colSet.insert(sum);
                }
                if (colSet.size() > 1 || *colSet.begin() != *rowSet.begin()) continue;

                int j = row;
                int k = col;
                int t = col + i;
                int val = 0;
                int another = 0;

                while (j <= row + i && k <= col + i)
                {
                    val += grid[j][k];
                    another += grid[j][t];
                    k++;
                    j++;
                    t--;
                }
                if (*rowSet.begin() != val || val != another) continue;

                ans = max(ans, i+1);
            }
            else
            {
                break;
            }
        }
    }

    int largestMagicSquare(vector<vector<int>>& grid)
    {
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                solve(i, j, grid);
            }
        }
        return ans;
    }
};
