class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans=0;
        for(int i=0;i<customers.size();i++){
             if(grumpy[i] == 0){
                ans+=customers[i];
             }
        }
        vector<int> prefix(customers.size(),0);
        for(int i=0;i<customers.size();i++){
              if(i == 0){
                   if(grumpy[i] == 1){
                      prefix[i]=customers[i];
                   }
                   continue;
              }
              int val=grumpy[i];
              prefix[i]=prefix[i-1]+ (val ? customers[i] : 0);
        }
        for(auto &j: prefix){
             cout<<j<<" ";
        }
        cout<<"\n";
        int maxi=INT_MIN;
        for(int i=0;i<customers.size();i++){
            if(i - minutes < 0){
                  maxi=max(maxi,prefix[i]);
                  continue;
            }
             maxi=max(maxi,prefix[i]-prefix[i-minutes]);
        }
        if(maxi != INT_MIN)
        ans+=maxi;
        return ans;

    }
};