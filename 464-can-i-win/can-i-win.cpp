class Solution {
public:
    int maxInt, target;
    unordered_map<int, bool> memo;

    bool dfs(int mask, int currentSum) {

        if (currentSum >= target) return false;

        if (memo.count(mask)) return memo[mask];

        for (int i = 1; i <= maxInt; i++) {
            if (!(mask & (1 << i))) { 
         
                if (!dfs(mask | (1 << i), currentSum + i)) {
                    return memo[mask] = true;
                }
            }
        }
        return memo[mask] = false;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        maxInt = maxChoosableInteger;
        target = desiredTotal;

        if (target <= 0) return true;

        int maxSum = maxInt * (maxInt + 1) / 2;
        if (maxSum < target) return false;

        return dfs(0, 0);
    }
};
