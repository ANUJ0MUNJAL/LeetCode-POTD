class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
       vector<vector<int>> arr(nums.size(),vector<int>(31,0));
     
       for(int i=0;i<nums.size();i++)
       {
           for(int j=0;j<31;j++)
           {
               int mask = 1 << j;
               if(mask & nums[i])
               {
             
                    arr[i][j]++;
               }
           }
           if(i!=0)
           {
                  for(int j=0;j<31;j++)
                  {
                       arr[i][j]+=arr[i-1][j];
                  }
           }

       }
      
       map<vector<bool>,int> mp;
       
       long long res = 0;
       vector<bool> temp(31,1);
       mp[temp]++;
       for(int i=0;i<nums.size();i++)
       {
         
            vector<bool> ans;
            bool flag=false;
            for(int j=0;j<31;j++)
            {
               
                if(arr[i][j] % 2 == 0)ans.push_back(true);
                else
                {
                   
                    ans.push_back(false);
                  
                }
            }
          
            
            res+=mp[ans];
            mp[ans]++;
       }
       return res;
    }
    
};