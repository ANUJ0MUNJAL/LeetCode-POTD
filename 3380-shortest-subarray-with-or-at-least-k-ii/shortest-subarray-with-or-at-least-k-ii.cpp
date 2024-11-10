class Solution {
public:

    int minimumSubarrayLength(vector<int>& nums, int k) {
       
        int slow=0;
        vector<vector<int>> freq(nums.size(),vector<int>(31,0));
        int value=0;
        int mini=INT_MAX;
        for(int i=0;i < nums.size() ;i++){
            value=value|nums[i];
            if(nums[i]>=k){
                return 1;
            }
           for(int j=0;j<31;j++){
               int mask=1<<j;

               if((nums[i] & mask)){
                   
                   freq[i][j]++;
                 
               }
           }
           
              for(int j=0;j<31;j++){
                  if(i>0)
                   freq[i][j]+=freq[i-1][j];
           }
            //   for(int j=0;j<31;j++){
            //     cout<<freq[i][j]<<" ";
            // }
            // cout<<"\n";
           
                while(slow<i && value>=k){
                      mini=min(mini,i-slow+1);
                       
                      for(int j=0;j<31;j++){
                           int mask=1<<j;
                          if((nums[slow]&mask))
                            freq[i][j]--;
                      }
    
           
                  
                       int ans=0;
                      for(int j=0;j<31;j++){
                          int mask=1<<j;
                          if(freq[i][j]>=1){
                              ans=ans|mask;
                          }
                      }
                        // cout<<ans<<"\n";
                    value=ans;
                   
                    slow++;
                      // cout<<value<<" "<<slow<<"\n";
                    if(value>=k)
                     mini=min(mini,i-slow+1);
                    // cout<<mini<<"\n";
                } 
            
            
        }
        if(mini==INT_MAX)
              return -1;
        return mini;
      
    }
};