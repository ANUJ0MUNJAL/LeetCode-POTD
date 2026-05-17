class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(arr[start] == 0)return true;
        queue<int> q;
        q.push(start);
        vector<int> visited(arr.size(),0);
        visited[start]=1;
        while(!q.empty())
        {
            auto el = q.front();
       
            q.pop();
            if(arr[el] == 0)return 1;
            
            int newa = el + arr[el];
            int newb = el - arr[el];

            

            if(newa >=0 and newa < arr.size() and !visited[newa]){
                visited[newa]=1;
                   q.push(newa);
            }
            if(newb >= 0 and newb < arr.size() and !visited[newb]){
                visited[newb] = 1;
                q.push(newb);
            }
        }

        return false;
    }
};