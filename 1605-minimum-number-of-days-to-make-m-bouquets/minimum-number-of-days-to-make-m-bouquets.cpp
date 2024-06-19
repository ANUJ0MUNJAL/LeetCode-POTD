class Solution {
public:
    bool possible(vector<int>&arr,int m,int k,int mid){
        int count=0,sum=0;
        for(int i=0;i<arr.size();i++){
           if(arr[i] > mid){
               if(count >= m)return true;
                sum=0;
                continue;
           }
           sum++;
           if(sum >= k){
              sum=0;
              count++;
           }
        } 
        if(count >= m)return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int start=1;
        int end=1e9+1;
        int ans=-1;
        while(start <= end){
              int mid=start+(end-start)/2;
              if(possible(bloomDay,m,k,mid)){
                  ans=mid;
                  end=mid-1;
              }else{
                start=mid+1;
              }
        }
        return ans;
    }
};