class Solution {
public:
    unordered_map<long long,int> mp;
    int solve(string &s,int k,long long int index,long long int uniquenumber,bool flag){
         long long key=((index<<27)|(uniquenumber<<1)|flag);
        if(mp.find(key)!=mp.end()){
            return mp[key];
        }
        
        if(index>=s.length())
             return 0;
       
        int value=s[index]-'a';
        long long newnumber=uniquenumber|(1<<value);
        int total=__builtin_popcount(newnumber);
        
        int result=0;
        if(total>k){
            result=1+solve(s,k,index+1,1<<value,flag);
        }else{
            result=solve(s,k,index+1,newnumber,flag);
        }
        
        if(flag==true){
            
            for(int i=0;i<26;i++){
                long long newnumber=uniquenumber|(1<<i);
                int total=__builtin_popcount(newnumber);
                if(total>k){
                    result=max(result,1+solve(s,k,index+1,1<<i,false));
                }else{
                    result=max(result,solve(s,k,index+1,newnumber,false));
                }
            }
        }
        return mp[key]=result;
    }
    
    int maxPartitionsAfterOperations(string s, int k) {
        return solve(s,k,0,0,true)+1;
    }
};