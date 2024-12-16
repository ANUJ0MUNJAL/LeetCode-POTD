class Solution {
public:
    vector<int> getFinalState(vector<int>& arr, int k, int multiplier) {
    while(k--)
    {
        int mini=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i] < arr[mini])
            {
                 mini=i;
            }
        }
        arr[mini]*=multiplier;
    }
        return arr;
    }
};