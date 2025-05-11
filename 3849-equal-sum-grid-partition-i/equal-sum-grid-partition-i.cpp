class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        vector<long long> horizontal;
        for(int i=0;i<grid.size();i++){
            long long sum = 0;
             for(int j=0;j<grid[i].size();j++){
                 sum+=grid[i][j];
             }
             if(horizontal.size() == 0)
                  horizontal.push_back(sum);
             else
               horizontal.push_back(horizontal.back()+sum);
        }
        for(int i=0;i<grid.size();i++){
            long long a = horizontal[i];
            long long b = horizontal[horizontal.size()-1]-a;
            if(a == b)return true;
        }
        vector<long long> vertical;

        for(int i=0;i<grid[0].size();i++){
            long long sum = 0;
            for(int j=0;j<grid.size();j++){
                 sum+=grid[j][i];
            }
            if(i == 0)
            vertical.push_back(sum);
            else
            vertical.push_back(sum+vertical.back());
        }

        for(int i=0;i<grid[0].size();i++){
            long long a = vertical[i];
            long long b = vertical[vertical.size()-1]-a;
            if(a == b)return true;
        }
        return false;
    }
};