class Solution {
public:
   

    long long minTime(vector<int>& skill, vector<int>& mana) {
         vector<long long> arr(skill.size(),0);

         for(int i=0;i<mana.size();i++)
         {
             if(i == 0)
             {
                for(int j=0;j<skill.size();j++)
                {
                     if(j == 0)arr[j]=mana[i]*skill[j];
                     else arr[j]=arr[j-1]+mana[i]*skill[j];
                }
             }else{
                for(int j=0;j<skill.size();j++)
                {
                    if(j == 0)
                    arr[j]=arr[j]+(mana[i]*skill[j]);
                    else
                    arr[j]=max(arr[j-1],arr[j])+(mana[i]*skill[j]);
                }

                for(int j=skill.size()-1;j>0;j--)
                {
                    arr[j-1]=arr[j]-(mana[i] * skill[j]);
                }
             }
         }
         return arr.back();
    }
};
