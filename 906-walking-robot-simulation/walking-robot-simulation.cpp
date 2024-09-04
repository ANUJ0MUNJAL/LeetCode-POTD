class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int row=0,col=0;
        bool north=true,south=false,east=false,west=false;
        set<pair<int,int>> st;
        for(auto j: obstacles)
        {
              st.insert({j[0],j[1]});
        }
        int maxi=0;
        for(int i=0;i<commands.size();i++)
         {
              if(commands[i]==-2)
              {
                  if(north)
                  {
                       north=false;
                       west=true;
                  }else if(south)
                  {
                       south=false;
                       east=true;
                  }else if(east)
                  {
                      east=false;
                      north=true;
                  }else{
                      west=false;
                      south=true;
                  }
                 
              }else if(commands[i]==-1)
              {
                  
                  if(north)
                  {
                       north=false;
                       east=true;
                  }else if(south)
                  {
                       south=false;
                       west=true;
                  }else if(east)
                  {
                       east=false;
                       south=true;
                  }else
                  {
                      west=false;
                      north=true;
                  }

              }else{
                    
                
                    for(int j=1;j<=commands[i];j++)
                    {
                         
                          if(north)
                          {
                               col+=1;
                            
                              
                               if(st.find({row,col})!=st.end())
                               {
                                  col-=1;
                                    break;
                               }
                                  maxi=max(maxi,(int)(pow(abs(row),2)+pow(abs(col),2)));
                          }else if(south)
                          {
                              col-=1;
                               
                              if(st.find({row,col})!=st.end())
                              {
                                  col+=1;
                                   break;
                              }
                                maxi=max(maxi,(int)(pow(abs(row),2)+pow(abs(col),2)));
                                
                          }else if(east)
                          { 
                             row+=1;
                          
                              if(st.find({row,col})!=st.end())
                              {
                                 row-=1;
                                  break;
                              }
                                maxi=max(maxi,(int)(pow(abs(row),2)+pow(abs(col),2)));
                              
                          }else
                          {
                             row-=1;
                           
                              if(st.find({row,col})!=st.end())
                              {
                                 row+=1;
                                 break;
                              }
                                maxi=max(maxi,(int)(pow(abs(row),2)+pow(abs(col),2)));
                          }
                    }

              }
         }
        
         return maxi;


    }
};