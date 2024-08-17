class Solution {
public:
   
    long long maxPoints(vector<vector<int>>& points) {
    
       vector<long long> prev(points[0].size(),0);
       for(int i=0;i<points[0].size();i++)
       {
           prev[i]=points[0][i];
       }

       for(int i=1;i<points.size();i++)
       {
         vector<long long> left(points[0].size(),0);
         vector<long long> right(points[0].size(),0);

         for(int j=0;j<points[0].size();j++)
         {
              if(j == 0)
              {
                 left[j]=prev[j];
              }
              else
              {
                  left[j]=max(prev[j],left[j-1]-1);
              }
         }
         for(int j=points[0].size()-1;j>=0;j--)
         {
              if(j==points[0].size()-1)
              {
                right[j]=prev[j];
              }
              else
              {
                 right[j]=max(prev[j],right[j+1]-1);
              }
         }

         vector<long long> curr(points[0].size(),0);

         for(int j=0;j<points[0].size();j++)
         {
            curr[j]=max(left[j],right[j])+points[i][j];
         }
         prev=curr;
       }
       return *max_element(prev.begin(),prev.end());
        
    }
};