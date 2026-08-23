class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int mini = INT_MAX;
        int index = -1;
        for(int i=0;i<drones.size();i++)
        {
            int x = abs(drones[i][0] - target[0]);
            int y = abs(drones[i][1] - target[1]);
            int range = drones[i][2];
           

            if(x + y <= range)
            {
                if(x + y < mini)
                {
                    mini = x + y;
                    index = i;
                }
            }
        }
        return index;
    }
};