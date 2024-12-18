class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        st.push(-1);
        vector<int> arr(prices.size());
        for(int i=prices.size()-1;i>=0;i--)
        {
            while(st.top()!=-1 and prices[st.top()] > prices[i])
            {
                st.pop();
            }
           if(st.top()==-1)
            arr[i]=st.top();
            else
              arr[i]=prices[st.top()];
            st.push(i);
        }
        for(int i=0;i<prices.size();i++)
        {
             if(arr[i] == -1)continue;
             else prices[i]-=arr[i];
        }
        return prices;
    }
};