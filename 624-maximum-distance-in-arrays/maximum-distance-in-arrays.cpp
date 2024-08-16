class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini1=INT_MAX,mini2=INT_MAX,maxi1=INT_MIN,maxi2=INT_MIN;
        int index1,index3;
        for(int i=0;i<arrays.size();i++)
        {
            if(arrays[i][0] < mini1)
            {
                 index1=i;
                 mini1=arrays[i][0];
            }
            if(arrays[i][arrays[i].size()-1] > maxi1)
            {
                 index3=i;
                 maxi1=arrays[i][arrays[i].size()-1];
            }
        }
        int index2;
        for(int i=0;i<arrays.size();i++)
        {
            if(i==index1)continue;
            if(arrays[i][0] < mini2)
            {
                mini2=arrays[i][0];
                index2=i;
            }

        }
        int index4;

        for(int i=0;i<arrays.size();i++)
        {
            if(i==index3)continue;
            if(arrays[i][arrays[i].size()-1] > maxi2)
            {
                maxi2=arrays[i][arrays[i].size()-1];
                index4=i;
            }
        }

        int ans=INT_MIN;

        if(index1 != index3)
        {
            ans=max(ans,maxi1-mini1);
        }else{
             ans=max({ans,maxi1-mini2,maxi2-mini1});
        }
        ans=max(ans,abs(mini1-mini2));
        return ans;




      


    }
};