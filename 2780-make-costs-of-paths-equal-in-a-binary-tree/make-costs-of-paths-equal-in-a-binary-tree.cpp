class Solution {
public:
    int ans=0;
    int solve(vector<int> &cost,int index)
    {
        if(index >= cost.size())return 0;
        int left=cost[index]+solve(cost,2*index+1);
        int right=cost[index]+solve(cost,2*index+2);
        ans+=(abs(left-right));
        return max(left,right);
    }

    int minIncrements(int n, vector<int>& cost) {
       int val=solve(cost,0);
       return ans;
    }
};
