class Solution {
public:
    int countHillValley(vector<int>& nums) {
         int count = 0;
         
         for(int i=1;i<nums.size()-1;i++)
         {
                 while(i+1 < nums.size() and nums[i] == nums[i+1])i++;
                 int j = i-1;
                 int a =0,b=0;
                 while(j >= 0)
                 {
                     if(nums[j] == nums[i])j--;
                     else break;
                 }
                 if(j < 0)continue;
                 else a = nums[j];
                 j = i+1;
                 while(j < nums.size())
                 {
                    if(nums[j] == nums[i])
                    {
                        j++;
                    }
                    else break;
                 }
                 if(j == nums.size())continue;
                 else b = nums[j];
                 cout<<a<<" "<<b<<endl;
                 if(a < nums[i] and nums[i] > b)count++;
                 else if(a > nums[i] and nums[i] < b)count++;
         }
         return count;
    }
};