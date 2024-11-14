class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;

        vector<int> evenFreq(100001);
        vector<int> oddFreq(100001);
        
        // Freq of odd and even occurrences
        for(int i=0; i<nums.size(); i++){
            if(i % 2 == 0) evenFreq[nums[i]]++;
            else oddFreq[nums[i]]++;
        }

        pair<int, int> evenHigh = getHighest(evenFreq, -1);
        pair<int, int> oddHigh = getHighest(oddFreq, -1);

        if (evenHigh.first != oddHigh.first) {
            return n - evenHigh.second - oddHigh.second;
        }

        pair<int, int> oddHigh2 = getHighest(oddFreq, oddHigh.first);
        pair<int, int> evenHigh2 = getHighest(evenFreq, evenHigh.first);

        return min(
            (n - evenHigh.second - oddHigh2.second), 
            (n - evenHigh2.second - oddHigh.second)
        );
    }

    pair<int, int> getHighest(vector<int> &vec, int excluded){
        int highNumber = 0, highFreq = 0;
        for(int i=0; i<vec.size(); i++){
            if(i != excluded && highFreq < vec[i]){
                highFreq = vec[i];
                highNumber = i;
            }
        }
        return make_pair(highNumber, highFreq);
    }
};