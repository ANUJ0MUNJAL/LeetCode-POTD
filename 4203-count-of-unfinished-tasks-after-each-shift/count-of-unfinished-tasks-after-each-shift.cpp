class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size();

        vector<long long> prefix(n);

        prefix[0] = tasks[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + tasks[i];
        }

        vector<int> ans;
        long long workDone = 0;

        for (int shift : shifts) {
            workDone += shift;

          
            int completed = upper_bound(
                prefix.begin(),
                prefix.end(),
                workDone
            ) - prefix.begin();

            if (completed == n) {
                ans.push_back(0);
                workDone = 0; 
            } else {
                ans.push_back(n - completed);
            }
        }

        return ans;
    }
};