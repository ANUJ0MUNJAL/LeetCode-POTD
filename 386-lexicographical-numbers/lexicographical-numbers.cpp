class Solution {
public:
    static bool cmp(int a,int b)
    {
        string first = to_string(a);
        string second= to_string(b);
        return first < second;
    }
    vector<int> lexicalOrder(int n) {
        vector<int> arr;
        for(int i=1;i<=n;i++)arr.push_back(i);
        sort(arr.begin(),arr.end(),cmp);
        return arr;
    }
};