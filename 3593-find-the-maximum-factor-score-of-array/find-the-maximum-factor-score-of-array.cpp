class Solution {
public:
    long long maxScore(vector<int>& nums) {
       long long mini = 0;
       if(nums.size()==1)return nums[0]*nums[0];
       for(int i=0;i<nums.size();i++)
       {
        long long g=0;
        long long product=1;
        for(int j=0;j<nums.size();j++)
        {
              if(j == i)continue;
             
              g=__gcd(g,1LL*nums[j]);
              product=(product*nums[j])/__gcd(product,1ll*nums[j]);
        }
         cout<<product<<"\n";
        mini=max(mini,g*product);
       }
       long long g=0;
        long long product=1;
       for(int i=0;i<nums.size();i++)
       {
              g=__gcd(g,1LL*nums[i]);
              product=(product*nums[i])/__gcd(product,1ll*nums[i]); 
       }
       mini=max(mini,g*product);
       return mini;
    }
};