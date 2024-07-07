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
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_pset;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        ll count=0;
        map<ll,ll> mp;
        mp[nums[0]]++;
        if(nums[0] == k)count++;
        for(int i=1;i<nums.size();i++){
            map<ll,ll> ndp;
            if(nums[i] == k)count++;
            ndp[nums[i]]++;
            for(auto &j: mp){
                 if((j.first & nums[i]) < k)continue;
                 ll val=j.first&nums[i];
                 ndp[val]+=j.second;
                 if(val == k)count+=j.second;
            }
            mp=ndp;
        }
        return count;

    }
    
};