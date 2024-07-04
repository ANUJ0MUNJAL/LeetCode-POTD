class Solution {
public:
    long long dp1[1001][501];
     long long dp2[1001][501];
    int solve(vector<int>&slices,int index,int count,int end){
         if(count == 0 || index > end)return 0;
         if(dp1[index][count] != -1) return dp1[index][count];
         int include=0;
         include=slices[index]+solve(slices,index+2,count-1,end);
         int exclude=solve(slices,index+1,count,end);
         return dp1[index][count]=max(include,exclude);
    }
     int solve1(vector<int>&slices,int index,int count,int end){
         if(count == 0 || index > end)return 0;
         if(dp2[index][count] != -1)return dp2[index][count];
         int include=0;
         include=slices[index]+solve1(slices,index+2,count-1,end);
         int exclude=solve1(slices,index+1,count,end);
         return dp2[index][count]=max(include,exclude);
    }
    int maxSizeSlices(vector<int>& slices) {
        memset(dp1,-1,sizeof(dp1));
        memset(dp2,-1,sizeof(dp2));

        return max(solve(slices,0,slices.size()/3,slices.size()-2),solve1(slices,1,slices.size()/3,slices.size()-1));
    }
};