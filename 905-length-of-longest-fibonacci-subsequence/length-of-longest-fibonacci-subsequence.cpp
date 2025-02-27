class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int len = 0;

        set<long long> st(arr.begin(),arr.end());

        for(int i=0;i<arr.size();i++)
        {
            for(int j=i+1;j<arr.size();j++)
            {
                int a = arr[i];
                int b = arr[j];
                int count = 2;
                while(st.count(a+b))
                {
                    int val = a+b;
                    a = b;
                    b = val;
                    count++;

                }
                len = max(len,count);
            }
        }
        return len <= 2 ? 0 : len;

    }
};