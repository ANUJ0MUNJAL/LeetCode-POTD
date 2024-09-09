class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
       map<long long, int> mp;
long long totalWidth = 0;
for (int i = 0; i < wall.size(); i++) {
    long long prefix = 0;
    for (int j = 0; j < wall[i].size() - 1; j++) {  
        prefix += wall[i][j];
        mp[prefix]++;
    }
    totalWidth = prefix + wall[i].back();  
}

int mini = wall.size();
for (auto& it : mp) {
    mini = min(mini, (int)wall.size() - it.second);
}
return mini;

    }
};