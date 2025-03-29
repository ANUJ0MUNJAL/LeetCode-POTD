class Solution {
public:
     int mod = 1e9 + 7;

    void primefactor(int value, int &count) {
        if (value == 1) {
            count = 0;  
            return;
        }
        count = 0;
        for (int i = 2; i * i <= value; i++) {
            if (value % i == 0) count++;
            while (value % i == 0) {
                value /= i;
            }
        }
        if (value > 1) count++;  
    }

      
    long long power(long long x,long long y)
    {
        if (y == 0)
            return 1;
        long long p = power(x, y / 2) % mod;
        p = (p * p) % mod;
        return y % 2 ? (p * x) % mod : p;
    }
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mp;
        vector<int> arr(n, 0);

        for (int i = 0; i < n; i++) {
            int count = 0;
            primefactor(nums[i], count);
            mp[i] = count;
        }
        vector<int> right(n,0);

        stack<int> st;
        st.push(-1);
        
       
        for(int i=nums.size()-1;i>=0;i--){
            while(st.top()!=-1 and mp[st.top()] <= mp[i])
            {
                st.pop();
            }
            if(st.top() == -1){
              
                right[i]=nums.size() - i -1;
            }else{
                right[i] = (st.top() - i -1);
            }

            st.push(i);


        }

        
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i}); 
        }
     
        int ans = 1;
        while (k > 0 && !pq.empty()) {
            auto el = pq.top();
            pq.pop();

            long long value = el.first;
            int count = el.second;
          
            long long left = 1, r = right[count]+1;
            int index = count - 1;
            

            while (index >= 0 && mp[index] < mp[count]) {  
                left++;
                index--;
            }
           
            
            long val = min(1LL*k, (1LL*left * r));
            k -= val;

            
            
            ans = (ans * power(value, val)) % mod;  

           


            if(k == 0)break;
        }
        return ans % mod;
    }
};
