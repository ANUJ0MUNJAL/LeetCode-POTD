class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<vector<string>> arr;
        for(int i=0;i<code.size();i++)
        {
            if(isActive[i])
            arr.push_back({businessLine[i],code[i]});
        }
        vector<string> ans;
        set<string> st;
        st.insert("electronics");
        st.insert("grocery");
        st.insert("pharmacy");
        st.insert("restaurant");
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++)
        {
            if(st.find(arr[i][0])!= st.end())
            {
                bool flag=true;
                for(auto j: arr[i][1])
                {

                   if(j == '_' or (j >= 'a' and j <='z') or(j >= 'A' and j <='Z') or (j >='0' and j <='9')){

                   }
                   else {
                    flag=false;
                    break;
                   }
                }
                if(flag and arr[i][1].length() > 0)
                {
                    ans.push_back(arr[i][1]);
                }
            }
        }
        return ans;
    }
};