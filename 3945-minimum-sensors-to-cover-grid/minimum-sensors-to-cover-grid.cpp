class Solution {
public:
    int minSensors(int n, int m, int k) {

       int row =  ceil(1.0*n/(2*k+1));
       int col =  ceil(1.0*m/(2*k+1));

       return row*col;
    }
};