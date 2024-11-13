#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
using std::cout;
using std::cin;
#define endl '\n'    

#define ll long long
#define loop(i,a,b) for(long long i=a;i<b;i++)
#define roop(i,a,b) for(long long i=a-1;i>=b;i--)
#define all(p) p.begin(),p.end()
#define pb(p) push_back(p);
long long pop_count(long long a){int res=0;while(a){res+=(a&1),a>>=1;}return res;}
template<class T> using _pq = priority_queue<T>;
template<class T> using _pqr = priority_queue<T, vector<T>, greater<T>>;
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_pset;

// lower <= nums[i] + nums[j]
// lower - nums[i] <= nums[j]
// nums[j] > 

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        ordered_multiset st;
        long long ans=0;
       
        for(int i=0;i<nums.size();i++)
        {
            long long val = st.order_of_key(upper-nums[i]+1);
            long long another = st.order_of_key(lower - nums[i]);
            if(val - another >=0)
            ans += (val - another);
            st.insert(nums[i]);
        }
        return ans;
    }
};
