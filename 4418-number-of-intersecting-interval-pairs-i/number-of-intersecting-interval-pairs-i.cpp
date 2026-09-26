#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, 
             tree_order_statistics_node_update> ordered_multiset;

class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        ordered_multiset oms;
        oms.insert(intervals[0][1]);
        int ans = 0;
        for(int i=1;i<intervals.size();i++)
        {
            int value = oms.size() - oms.order_of_key(intervals[i][0]);
            ans+=value;
            oms.insert(intervals[i][1]);

        }
        return ans;
    }
};