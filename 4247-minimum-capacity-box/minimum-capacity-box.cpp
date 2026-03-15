class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        long long mini = INT_MAX;
        int index = -1;
        for(int i=0;i<capacity.size();i++)
        {
            if(capacity[i] < mini and capacity[i] >= itemSize)
            {
                mini = capacity[i];
                index = i;
            }
        }
        return index;
    }
};