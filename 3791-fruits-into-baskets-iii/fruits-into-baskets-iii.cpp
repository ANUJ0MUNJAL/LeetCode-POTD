
class Solution {
    
public:

    int N;
vector<int> v, Tree;
void buildTree(int tidx, int lo, int hi){

    if(lo==hi){
        Tree[tidx] = v[hi];
        return;
    }

    int mid = (lo+hi)/2;

    buildTree(2*tidx+1, lo, mid);
    buildTree(2*tidx+2, mid+1, hi);

    Tree[tidx] = max(Tree[2*tidx+1] ,Tree[2*tidx+2]);

}

void updateTree(int tidx, int lo, int hi, int idx, int val){

    if(lo==hi){
        Tree[tidx] = -1;
        return;
    }

    int mid = (lo+hi)/2;

    if(idx<=mid)
        updateTree(2*tidx+1, lo, mid, idx, val);
    else
        updateTree(2*tidx+2, mid+1, hi, idx, val);

    Tree[tidx] = max(Tree[2*tidx+1],Tree[2*tidx+2]);

}

  int find(int value,int low,int high,int index)
  {
       if(low == high)
       {
         
          int val = Tree[index];
          if(val >= value)
          updateTree(1,0,N-1,low,-1);
          
          return val;
       }
         int mid = (low+high)/2;
   
       if(Tree[2*index+1] >= value)
       {
          return find(value,low,mid,2*index+1);
       }else{
           return find(value,mid+1,high,2*index+2);
       }
  }


    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        N = baskets.size();
        v = baskets;
        Tree.resize(10*N);
        buildTree(1,0,baskets.size()-1);
        int count = 0;
        for(int i=0;i<fruits.size();i++)
        {
            // for(auto j: Tree)cout<<j<<" ";
            int value = find(fruits[i],0,baskets.size()-1,1);
            // cout<<value<<endl;
            if(value < fruits[i])count++;
        }
        return count;

    }
};