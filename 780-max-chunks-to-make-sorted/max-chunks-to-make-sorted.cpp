class Solution {
public:
    bool possible(vector<int>&arr,int end,int index,vector<int>&temp,vector<int>ans)
    {
    
        if(end == 0 and temp == ans)
        {
             return true;
        }
        if(end <= 0 or index >= arr.size())return false;
         vector<int> val;
        for(int i=index;i<arr.size();i++)
        {
            
            val.push_back(arr[i]);
             
            sort(val.begin(),val.end());
             for(auto j: val)ans.push_back(j);
         
            if(possible(arr,end-1,i+1,temp,ans))
            {
                return true;
            }
            for(int j=0;j<val.size();j++)ans.pop_back();

           
        }
        return false;
        
    }
    int maxChunksToSorted(vector<int>& arr) {
        
        int end = arr.size();
        vector<int> temp = arr;
        sort(temp.begin(),temp.end());
        vector<int> ans;
        while(end >= 1)
        {
             ans.clear();
             if(possible(arr,end,0,temp,ans))
             {
              
                 return end;
             }
             end--;
        }
        return 1;

    }
};