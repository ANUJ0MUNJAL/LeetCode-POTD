// #include <bits/stdc++.h>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using namespace std;
// using std::cout;
// using std::cin;
// #define endl '\n'    
// #ifndef ONLINE_JUDGE
// #include "debug.cpp"
// #define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
// #define debugArr(arr, size) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printerArr(#arr, arr, size)
// #endif
#define ll long long
// #define loop(i,a,b) for(long long i=a;i<b;i++)
// #define roop(i,a,b) for(long long i=a-1;i>=b;i--)
// #define all(p) p.begin(),p.end()
// #define pb(p) push_back(p);
// long long pop_count(long long a){int res=0;while(a){res+=(a&1),a>>=1;}return res;}
// template<class T> using _pq = priority_queue<T>;
// template<class T> using _pqr = priority_queue<T, vector<T>, greater<T>>;
// template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
// template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_pset;
 
 
 
class Solution {
public:
       int maximumLength(vector<int>& nums, int k) {
            int n = nums.size();
        vector<unordered_map<int, int>> dp(n);  

        int maxi = 1;

        for (int i = 0; i < n; ++i) {
            dp[i][nums[i] % k] = 1;  
            for (int j = 0; j < i; ++j) {
                int val = (nums[j] + nums[i]) % k;
                if (dp[j].count(val) > 0) {
                    dp[i][val] = max(dp[i][val], dp[j][val] + 1);
                } else {
                    dp[i][val] = max(dp[i][val], 2);
                }
                maxi = max(maxi, dp[i][val]);
            }
        }

        return maxi;
        
    }
};