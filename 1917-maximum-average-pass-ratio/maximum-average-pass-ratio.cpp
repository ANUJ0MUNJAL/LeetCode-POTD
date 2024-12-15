class Solution {
public:
    double solve(int a,int b)
    {
        return (double)(a+1)/(b+1)-(double)(a)/b;
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extra) {
        priority_queue<pair<double,pair<int,int>>>pq;
        for(auto j: classes)
        {
             pq.push({solve(j[0],j[1]),{j[0],j[1]}});
             
        }
        while(extra--)
        {
              auto el = pq.top();
              int a = pq.top().second.first;
              int b = pq.top().second.second;
              pq.pop();
              a++;
              b++;
              pq.push({solve(a,b),{a,b}});
        }
        double sum = 0;
        while(!pq.empty())
        {
            cout<<pq.top().first<<endl;
            sum+=(double)pq.top().second.first/pq.top().second.second;
            pq.pop();
        }
        return sum/classes.size();

    }
};