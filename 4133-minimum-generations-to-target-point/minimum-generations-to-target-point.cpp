class Solution {
public:
    vector<int> solve(vector<vector<int>>&points,int i,int j)
    {
        int x = (points[i][0] + points[j][0])/2;
        int y = (points[i][1] + points[j][1])/2;
        int z = (points[i][2] + points[j][2])/2;
        return {x,y,z};
    }
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        
        int k = 15;
        int count = 0;
        set<vector<int>> st;
        for(auto j: points)
        {
            st.insert(j);
        }
        if(st.find(target) != st.end())return 0;
        while(k -- )
        {
            set<vector<int>> st;
            
            for(int i=0;i<points.size();i++)
            {
                for(int j=i;j<points.size();j++)
                {
                     vector<int> temp = solve(points,i,j);
                     st.insert(temp);
                }
            }

            if(st.find(target) != st.end())
            {
                return count+1;
            }
          
            points.clear();

            for(auto j: st)
            {
                points.push_back(j);
            }
            count++;

        }
        return -1;
    }
};