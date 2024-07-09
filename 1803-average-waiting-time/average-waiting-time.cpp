class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans=0;
        int val=0;
        for(int i=0;i<customers.size();i++){
              if(i == 0){
                   val=customers[i][0]+customers[i][1];
                   ans+=(val-customers[i][0]);
                
              }else{

                   int ans1= val - customers[i][0];
                     if(ans1 < 0){
                       ans1=0;
                       val=customers[i][0]+customers[i][1];
                       ans+=customers[i][1];
                   }else{
                       ans+=(ans1+customers[i][1]);
                       val+=customers[i][1];

                   }
                
                 
              }
        }
     
        return ans/customers.size();
    }
};