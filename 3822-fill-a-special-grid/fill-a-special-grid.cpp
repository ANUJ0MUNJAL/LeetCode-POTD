class Solution {
public:
    vector<vector<int>> specialGrid(int N) {
     
           vector<vector<int>> temp = {{0}};
           if(N == 0)return temp;
   int value = 0;
   int n = N;
vector<vector<int>> ans;

while (value < n) {
    int currSize = pow(2, value);
    vector<vector<int>> grid(2 * currSize, vector<int>(2 * currSize, 0));
    int maxi = 0;

    for (int i = 0; i < currSize; i++) {
        for (int j = currSize; j < 2 * currSize; j++) {
            grid[i][j] = temp[i][j - currSize];
            maxi = max(maxi, grid[i][j] + 1);
        }
    }

    int val = maxi;

    for (int i = currSize; i < 2 * currSize; i++) {
        for (int j = currSize; j < 2 * currSize; j++) {
            grid[i][j] = temp[i - currSize][j - currSize] + val;
            maxi = max(maxi, grid[i][j] + 1);
        }
    }

    val = maxi;

    for (int i = currSize; i < 2 * currSize; i++) {
        for (int j = 0; j < currSize; j++) {
            grid[i][j] = temp[i - currSize][j] + val;
            maxi = max(maxi, grid[i][j] + 1);
        }
    }

    val = maxi;

    for (int i = 0; i < currSize; i++) {
        for (int j = 0; j < currSize; j++) {
            grid[i][j] = temp[i][j] + val;
            maxi = max(maxi, grid[i][j] + 1);
        }
    }

    value++;
    temp = grid;
    ans = grid;
}
        return ans;
    }
};