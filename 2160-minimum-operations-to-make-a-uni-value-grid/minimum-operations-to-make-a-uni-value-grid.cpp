class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> temp;
        map<int,int> mp;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++){
                temp.push_back(grid[i][j]);
                mp[grid[i][j] % x]++;
            }
        }
        if(mp.size() > 1)return -1;

        sort(temp.begin(),temp.end());

        int value = temp[temp.size()/2];
        int count = 0;

        for(int i=0;i<temp.size();i++)
        {
            if(temp[i] < value){
                int val = value - temp[i];
                count+=(val/x);
            }else if(temp[i] > value){
                int val = temp[i] - value;
                count+=(val/x);
            }
        }
        return count;
       
    }
};