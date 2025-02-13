class Solution {
public:
   
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        vector<int> arr(groups.size(),-1);
        map<int,set<int>> mp;
        vector<int> temp(1e5+1,-1);
        vector<int> vis(1e5+1,0);
        for(int i=0;i<elements.size();i++)
        {
            if(vis[elements[i]])continue;
            int val = elements[i];
            vis[val]=1;
            for(int j=val;j<temp.size();j+=val)
            {
               if(temp[j]==-1)
                temp[j]=i;
            }
        }

        for(int i=0;i<groups.size();i++){
            arr[i]=temp[groups[i]];
        }
        return arr;

    }
};