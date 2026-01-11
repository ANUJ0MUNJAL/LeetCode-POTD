

class Solution {
public:
       vector<int> smallestnext(vector<int>& heights)
    {
        int n=heights.size();
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--)
        {
            int curr=heights[i];
            while((s.top()!=-1) &&(heights[s.top()]>=curr))
            {
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
      vector<int> smallestprev(vector<int>& heights)
    {
          int n=heights.size();
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            int curr=heights[i];
            while((s.top()!=-1) &&(heights[s.top()]>=curr))
            {
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
          return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> next(n);
        vector<int> prev(n);
        next=smallestnext(heights);
         prev=smallestprev(heights);
        int area=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int l=heights[i];
            if(next[i]==-1)
            {
                next[i]=n;
            }
            int b=next[i]-prev[i]-1;
            int newarea=l*b;
            area=max(area,newarea);
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
           vector<int> temp(matrix[0].size(),0);

        int maxi=INT_MIN;
        for(int i=0;i<matrix.size();i++){
      // 0 1
      // 1 0     
                for(int j=0;j<matrix[i].size();j++){
                    if(matrix[i][j]=='0'){
                      temp[j]=0;
                    }else{
                    temp[j]+=matrix[i][j]-'0';
                    }
                }
                maxi=max(maxi,largestRectangleArea(temp));
            
        }
        return maxi;
    }
};