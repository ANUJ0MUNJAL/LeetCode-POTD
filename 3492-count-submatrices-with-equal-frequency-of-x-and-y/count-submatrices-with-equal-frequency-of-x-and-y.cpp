#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
using std::cout;
using std::cin;
#define endl '\n'    

#define ll long long
#define loop(i,a,b) for(long long i=a;i<b;i++)
#define roop(i,a,b) for(long long i=a-1;i>=b;i--)
#define all(p) p.begin(),p.end()
#define pb(p) push_back(p);
long long pop_count(long long a){int res=0;while(a){res+=(a&1),a>>=1;}return res;}
template<class T> using _pq = priority_queue<T>;
template<class T> using _pqr = priority_queue<T, vector<T>, greater<T>>;
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_pset;

class Solution {
public:
  int numberOfSubmatrices(vector<vector<char>>& grid) {
         vector<vector<pair<int,int>>> arr(grid.size(),vector<pair<int,int>>(grid[0].size()));
        if(grid[0][0]=='X')
           arr[0][0]={1,0};
        else if(grid[0][0]=='Y'){
            arr[0][0]={0,1};
        }else{
            arr[0][0]={0,0};
        }
        for(int i=1;i<grid.size();i++){
             if(grid[i][0]=='X'){
                   arr[i][0].first=arr[i-1][0].first+1;
                   arr[i][0].second=arr[i-1][0].second;
             }else if(grid[i][0]=='Y'){
                   arr[i][0].first=arr[i-1][0].first;
                   arr[i][0].second=arr[i-1][0].second+1;
             }else{
                  arr[i][0]=arr[i-1][0];
             }
              
        }

         for(int i=1;i<grid[0].size();i++){
             if(grid[0][i]=='X'){
                   arr[0][i].first=arr[0][i-1].first+1;
                   arr[0][i].second=arr[0][i-1].second;
             }else if(grid[0][i]=='Y'){
                   arr[0][i].first=arr[0][i-1].first;
                   arr[0][i].second=arr[0][i-1].second+1;
             }else{
                  arr[0][i]=arr[0][i-1];
             }
              
        }

        for(int i=1;i<grid.size();i++){
               for(int j=1;j<grid[0].size();j++){
                     int a=arr[i][j-1].first+arr[i-1][j].first-arr[i-1][j-1].first;
                     int b=arr[i][j-1].second+arr[i-1][j].second-arr[i-1][j-1].second;

                     if(grid[i][j]=='X'){
                          a+=1;
                     }else if(grid[i][j]=='Y'){
                          b+=1;
                     }
                     arr[i][j]={a,b};
               }
        }
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                 if(arr[i][j].first==0)continue;
                 if(arr[i][j].first==arr[i][j].second){
                       count++;
                 }
            }
        }
        return count;
    }
    
};