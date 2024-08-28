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

class DisjointSet {
    vector<int> rank, parent, size; 
public: 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 

void dfs(vector<vector<int>>&grid,int row,int col,int startrow,int startcol,DisjointSet &ds)
{
      if(row >= grid.size() || row < 0 || col >= grid[0].size() || col < 0 || grid[row][col]==0)return;
      ds.unionBySize(row *grid[0].size()+col,startrow*grid[0].size()+startcol);
      grid[row][col]=0;
      dfs(grid,row+1,col,startrow,startcol,ds);
      dfs(grid,row-1,col,startrow,startcol,ds);
      dfs(grid,row,col+1,startrow,startcol,ds);
      dfs(grid,row,col-1,startrow,startcol,ds);
}
bool flag=true;
void dfs2(vector<vector<int>>&grid,DisjointSet &ds,vector<vector<int>>&grid1,int row,int col)
{
      if(row >= grid.size() || row < 0 || col >= grid[0].size() || col < 0 || grid[row][col]==0)return;
      if(grid1[row][col]==0)
      {
       
        flag=false;
      }
      
     
      
      grid[row][col]=0;
        dfs2(grid,ds,grid1,row+1,col);
         dfs2(grid,ds,grid1,row-1,col);
          dfs2(grid,ds,grid1,row,col+1);
            dfs2(grid,ds,grid1,row,col-1);

}
class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
          DisjointSet ds(grid1.size()*grid1[0].size()+1);
          vector<vector<int>>temp=grid1;
         for(int i=0;i<grid1.size();i++)
         {
              for(int j=0;j<grid1[0].size();j++)
              {
                    if(grid1[i][j] == 1)
                    {
                          dfs(grid1,i,j,i,j,ds);
                    }


              }
         }
        
        
         int count=0;
         for(int i=0;i<grid2.size();i++)
         {
              for(int j=0;j<grid2[0].size();j++)
              {
                   if(grid2[i][j]==1)
                   {
                     
                      flag=true;
                      dfs2(grid2,ds,temp,i,j);
                      if(flag)count++;
                   }
              }
         }
         return count;
    }
};


