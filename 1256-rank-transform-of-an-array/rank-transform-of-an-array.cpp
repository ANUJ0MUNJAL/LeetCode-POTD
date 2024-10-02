class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int> mp;
        vector<int> temp=arr;
        sort(arr.begin(),arr.end());
        arr.erase(unique(arr.begin(),arr.end()),arr.end());
       
        for(int i=0;i<arr.size();i++)
        {
            
             mp[arr[i]]=i+1;
        }
        for(int i=0;i<temp.size();i++)
        {
            temp[i]=mp[temp[i]];
        }
        return temp;
    }
};