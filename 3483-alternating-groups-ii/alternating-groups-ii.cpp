class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n=colors.size();
        for(int i=0;i<n;i++){
            colors.push_back(colors[i]);
        }
        
        int count=1;
        int ans=0;
        for(int i=0;i<n+k-2;i++){
              if(colors[i] != colors[i+1]){
                    count++;
              }else{
                  if(count >= k)
                   ans+=count-k+1;
                  count=1;
              }
        }
        if(count >= k){
             ans+=count-k+1;
          }
        return ans;
        
    }
};