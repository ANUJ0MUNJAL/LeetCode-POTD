class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
          set<int> st;
          for(int i=2;i<=1000;i++)
          {
              int val = i;
              bool flag=true;
              for(int j=2;j<val;j++)
              {
                 if(val % j == 0)
                 {
                     flag=false;
                     break;
                 }
              }
              if(flag)
              {
                  st.insert(i);
              }
          }
          for(int i=0;i<nums.size();i++)
          {
              auto itr =st.lower_bound(nums[i]);
              if(itr == st.begin())continue;
              itr--;
          
              if(i == 0)
              {
                nums[i]=nums[i]-*itr;
              }else{
              while(true){
               
                 if(nums[i]-*itr > nums[i-1])
                 {
                     nums[i]=nums[i]-*itr;
                     break;
                 }else{
                     itr--;

                     if(itr  == st.begin())
                     {
                         
                          if(nums[i] - *itr > nums[i-1])nums[i]=nums[i]-*itr;
                          break; 
                     }
                 }
              }
              }
          }
         
          for(int i=0;i<nums.size()-1;i++)
          {
             if(nums[i] >= nums[i+1])return false;
             
          }
          return true;

    }
};