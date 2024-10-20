class Solution {
public:
    int solve(int num)
    {
   for(int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0){
            if(i == num/i)
                return i;  
            else
               return num/i;
        }
    }
    return -1;

    }
    int minOperations(vector<int>& nums) {
        vector<pair<int,int>> arr;
        for(int i=0;i<nums.size();i++)
        {
              int val = solve(nums[i]);
              if(val == -1)
              {
                arr.push_back({nums[i],nums[i]});
              }else{
                arr.push_back({nums[i],val});
              }
        }
        int prev=arr[arr.size()-1].first;
        int count=0;
        for(int i=arr.size()-2;i>=0;i--)
        {
              int val = arr[i].first;
             
              while(val > prev and val != arr[i].second and  val % arr[i].second == 0)
              {
                
                  val/=arr[i].second;
                  count++;
              }
              if(prev < val)return -1;
              prev = val;
        }
        return count;
        
    }
};