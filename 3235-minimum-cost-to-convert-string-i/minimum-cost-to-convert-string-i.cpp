#define ll long long
class Solution {
public:
   vector<ll> dijkstra(char source,unordered_map<char,vector<pair<char,long long>>>&mp){
        priority_queue<pair<ll,char>,vector<pair<ll,char>>,greater<pair<ll,char>>> pq;
        pq.push({0,source});

        vector<ll> distance(26,INT_MAX);
        distance[source-'a']=0;
        while(!pq.empty()){
              
              auto element=pq.top();
              pq.pop();

              ll dis=element.first;
              char parent=element.second;
              if(distance[parent-'a']<dis){
                  continue;
              }
              if(distance[parent-'a']>dis){
                  distance[parent-'a']=dis;
              }

              for(auto neighbour: mp[parent]){
                
                  char child=neighbour.first;
                  ll val=neighbour.second;

                  if(distance[child-'a']>val+dis){
                      distance[child-'a']=val+dis;
                         pq.push({distance[child-'a'],child});
                  }
               
              }
        }
        return distance;
    }
    
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_map<char,vector<pair<char,long long>>> mp;
        unordered_map<char,vector<ll>>mp1;
        for(int i=0;i<original.size();i++){
            mp[original[i]].push_back({changed[i],cost[i]});
        }
        
        long long ans=0;

        for(char i='a';i<='z';i++){
            mp1[i]=dijkstra(i,mp);
        }
       for(auto j: mp1){
           cout<<j.first<<"->";
           for(auto i: mp1[j.first]){
               cout<<i<<" ";
           }
           cout<<endl;
       }

       for(int i=0;i<source.length();i++){
           if(source[i]!=target[i]){
               if(mp1[source[i]][target[i]-'a']==INT_MAX)
                  return -1;
                ans+=mp1[source[i]][target[i]-'a'];
           }
       }
        return ans;
    }
};