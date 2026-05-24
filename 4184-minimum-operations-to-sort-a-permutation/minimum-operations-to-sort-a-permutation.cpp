class Solution {
    bool sorted(vector<int> &nums){
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i-1]) return false; 
        }
        return true;
    }

    int solve(vector<int>& nums){
        if(sorted(nums)) return 0;
        else {
            vector<int> it = nums;
            reverse(it.begin(), it.end());
            if(sorted(it)) return 1;
        }

        int n = nums.size(), last = -1, st = -1, ans = INT_MAX;
        for(int i = 0; i < n; i++){
            if(nums[i] == n-1) {
                last = i;
            }
            if(nums[i] == 0) st = i;
        }
        vector<int> temp;

        for(int i = st; i < n; i++) temp.push_back(nums[i]);
        for(int i = 0; i < st; i++) temp.push_back(nums[i]);

        if(sorted(temp)) ans = st;
        
        temp = {};
        for(int i = last; i < n; i++) temp.push_back(nums[i]);
        for(int i = 0; i < last; i++) temp.push_back(nums[i]);
        reverse(temp.begin(), temp.end());

        if(sorted(temp)) return min(ans,  last + 1);
        
        return ans == INT_MAX ? -1: ans;
    }
public:
    int minOperations(vector<int>& nums) {
        int op1 = solve(nums);

        reverse(nums.begin(), nums.end());
        int op2 = solve(nums) ;
    
        if(op1 == -1 && op2 == -1) return -1;
        else if(op1 == -1) return op2+1;
        else if(op2 == -1) return op1;
        return min(op1, op2+1);
    }
};