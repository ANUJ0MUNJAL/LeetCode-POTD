class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int> mp;
        set<string> st;
        for(auto j: arr)mp[j]++;
        for(auto j: mp){
            if(j.second==1)st.insert(j.first);
        }
        if(st.size()<k)return "";
        int count=0;
        for(int i=0;i<arr.size();i++){
            if(st.find(arr[i])!=st.end()){
                 count++;
                 if(count==k)return arr[i];
            }
        }
        return "";
        }
};