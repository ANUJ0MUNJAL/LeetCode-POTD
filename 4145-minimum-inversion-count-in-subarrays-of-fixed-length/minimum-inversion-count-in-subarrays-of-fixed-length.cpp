#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;


typedef tree<pair<int,int>, null_type, less<pair<int,int>>,
             rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

 
class Solution {
public:
    long long minInversionCount(vector<int>& nums, int k) {
        ordered_multiset st;
        long long count = 0;
        long long mini = LLONG_MAX;

        for(int i = 0; i < nums.size(); i++) {
            if(i < k) {
                int value = st.order_of_key({nums[i], 1e9});
                st.insert({nums[i], i});
                count += (i - value);
            } else {
                mini = min(mini, count);

                int rem = nums[i - k];
                count -= st.order_of_key({rem, i - k});
                st.erase({rem, i - k});

                int value = st.order_of_key({nums[i], 1e9});
                st.insert({nums[i], i});
                count += (k - value - 1);

                mini = min(mini, count);
            }
        }

        mini = min(mini, count);
        return mini;
    }
};
