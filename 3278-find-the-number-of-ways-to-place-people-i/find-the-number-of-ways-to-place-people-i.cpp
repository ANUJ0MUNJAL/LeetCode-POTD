class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int count=0;
        
         
         for(int i=0;i<points.size();i++){
              int chirow=points[i][0];
              int chicol=points[i][1];
            for(int j=0;j<points.size();j++){
                if(j==i)
                     continue;
                int takrow=points[j][0];
                int takcol=points[j][1];
                if(takrow==chirow){
                    if(takcol > chicol)
                        continue;
                    bool flag=true;
                    for(int k=0;k<points.size();k++){
                        if(k==i or k==j)
                            continue;
                        if(points[k][0]==takrow){
                             if(points[k][1] < chicol  and points[k][1] > takcol){
                                 flag=false;
                                 break;
                             }
                        }
                    }
                    if(flag){
                        
                        count++;
                    }
                }
                else if(takcol==chicol){
                    
                    if(takrow < chirow)
                        continue;
                    bool flag=true;
                    for(int k=0;k<points.size();k++){
                        if(k==i or k==j)
                            continue;
                        if(points[k][1]==takcol){
                            // cout<<points[k][0]<<endl;
                             if(points[k][0] > chirow  and points[k][0] < takrow){
                                 flag=false;
                                 break;
                             }
                        }
                    }
                    if(flag){
                        count++;
                    }
                    
                    
                }
                else{
                    continue;
                }
                
                
                }
            }
         
        
        
         for(int i=0;i<points.size();i++){
              int chirow=points[i][0];
              int chicol=points[i][1];
            for(int j=0;j<points.size();j++){
                if(j==i)
                     continue;
                int takrow=points[j][0];
                int takcol=points[j][1];
                
               
                if(takrow>chirow && chicol>takcol){
                    bool flag=true;
                    for(int k=0;k<points.size();k++){
                        if(k==i || k==j)
                             continue;
                        if(points[k][0]>=chirow && points[k][0]<=takrow){
                            if(points[k][1]>=takcol && points[k][1]<=chicol){
                                flag=false;
                                break;
                            }
                        }
                    }
                    if(flag==true){
                        count++;
                    }
                }
            }
         }
        return count;
    }
};