class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int sum = 0;
        for(auto j: machines)sum+=j;
        if(sum % machines.size() != 0)return -1;
        int val = sum / machines.size();

        vector<int> left(machines.size(),0);
        vector<int> right(machines.size(),0);
        for(int i=1;i<machines.size();i++)
        {
            left[i] = left[i-1] + machines[i-1];
        }
        for(int i= machines.size()-2;i>=0;i--)
        {
            right[i] = right[i+1] + machines[i+1];
        }
        int move = 0;

        for(int i=0;i<machines.size();i++)
        {
            int l = i*val;
            int r = (machines.size()-i-1)*val;
            int totalleft = 0,totalright = 0;
            if(l > left[i])
            {
                totalleft = l - left[i];
            }
            if(r > right[i])
            {
                totalright = r - right[i];
            }

            move = max(move,totalleft+totalright);
        }
        return move;
    }
};