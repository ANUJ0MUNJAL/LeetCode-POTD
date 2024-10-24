class Solution {
public:
    
    vector<int> numsSameConsecDiff(int n, int k) {
        queue<string> q;
        for(int i=1;i<=9;i++)
        {
            q.push(to_string(i));
        }
        vector<int> ans;
        while(!q.empty())
        {
            auto el = q.front();
            q.pop();
            cout<<el<<"\n";
           if(el.length() == n)ans.push_back(stoi(el));
          if(el.length() < n){
            
            for(int i=0;i<=9;i++)
            {
                int val = el[el.length()-1]-'0';
                if(abs(val - i) == k)
                {
                     string temp = el+to_string(i);
                     q.push(temp);
                     
                }
            }
          }
    
        }
        return ans;
    }

};