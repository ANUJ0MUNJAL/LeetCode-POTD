class Solution {
public:
    int solve(vector<vector<int>>&square,double value)
    {
        double down =0,up=0;
        for(int i=0;i<square.size();i++)
        {
            if(1.0*(square[i][1] + square[i][2]) <= value)
            {
                  down += pow(square[i][2],2);
            }else if(square[i][1] >= value)
            {
                  up += pow(square[i][2],2);
            }else{
                double downb = value - square[i][1];
                down += (downb * square[i][2]);

                double upb = square[i][1]+square[i][2] - value;
                up += (upb*square[i][2]);
            }
            
        }
       
        if(abs(down - up) <= 0.00001)return 0;
        if(up > down)return 1;
        return 2;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double start = 0;
        double end = 1e9;
        double ans = 0;
        while(abs(start - end) > 0.00001)
        {
            double mid = (start+end)/2.0;
            int value = solve(squares,mid);
            if(value == 0)
            {
                ans = mid;
                end = mid;
            }
            else if(value == 1)
            {
                start = mid;
            }else{
                end = mid;
            }
            ans = mid;
        }
        return ans;
    }
};