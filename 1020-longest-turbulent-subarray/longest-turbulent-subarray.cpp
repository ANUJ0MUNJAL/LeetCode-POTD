class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int start=0;
        int flag=-1;
        int maxi=1;
        for(int i=1;i<arr.size();i++)
        {
             if(flag == -1)
             {
                  if(arr[i] > arr[i-1])flag=1;
                  else if(arr[i] < arr[i-1])flag=0;
                  else{
                    flag=-1;
                    start=i;
                  }
                  
                  maxi=max(maxi,i-start+1);
                  continue;
             }
            
            if(flag)
            {
               if(arr[i] < arr[i-1])flag=0;
               else if(arr[i] > arr[i-1])
               {
                start=i-1;
                flag=1;
               }else{
                  start=i;
                  flag=-1;
               }
            }else{
                if(arr[i] > arr[i-1])flag=1;
                else if(arr[i] < arr[i-1])
                {
                    start=i-1; 
                    flag=0;
                }else{
                     start=i;
                     flag=-1;
                }
            }
            maxi=max(maxi,i-start+1);
        }
        return maxi;
    }
};