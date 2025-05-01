class Solution {
public:
    bool possible(multiset<int>& st, vector<int>& tasks, int k, int pills, int strength) {
        int i = k - 1;
        
        while (i >= 0 && !st.empty()) {
            int task = tasks[i];

            if (*st.rbegin() >= task) {
                st.erase(prev(st.end()));
                i--;
            }

            else if (pills > 0) {
                auto it = st.lower_bound(task - strength);
                if (it != st.end()) {
                    st.erase(it);
                    pills--;
                    i--;
                } else {
                
                    return false;
                }
            }
     
            else {
                return false;
            }
        }

        return i < 0;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end(), greater<int>());

        int start = 0, end = min(tasks.size(), workers.size());
        int ans = 0;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            multiset<int> st;
            for (int i = 0; i < mid; i++) {
                st.insert(workers[i]);
            }

            vector<int> temp(tasks.begin(), tasks.begin() + mid);

            if (possible(st, temp, mid, pills, strength)) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return ans;
    }
};
