class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {       
        int flips=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
              if(flips % 2 == 0){
                   if(nums[i] == 0){
                        if(i+k-1 >= nums.size())return -1;
                        flips++;
                        count++;
                        nums[i]=1;
                   }else{
                      nums[i]=0;
                   }
              }else{
                  if(nums[i] == 1){
                      if(i+k-1 >= nums.size()) return -1;
                      flips++;
                      count++;
                      nums[i]=1;
                  }else{
                     nums[i]=0;
                  }
              }
              if(i - k+1>=0){
                flips-=nums[i-k+1];
              }
              cout<<flips<<"\n";
        }
        return count;
    }
};