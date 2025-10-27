class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int len=bank[0].length();
        string temp=string(len,'0');
        vector<pair<string,int>> ans;
        for(int i=0;i<bank.size();i++){
            if(bank[i]==temp)
               continue;
            int count=0;
            for(int j=0;j<bank[i].length();j++){
                if(bank[i][j]=='1')
                    count++;
            }
            ans.push_back({bank[i],count});
        }
        int total=0;
        for(int i=1;i<ans.size();i++){
           total+=ans[i].second*ans[i-1].second;
        }
        return total;
    }
};