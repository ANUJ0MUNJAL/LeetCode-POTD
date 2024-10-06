class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> arr;
        string temp="";
        for(int i =0;i<sentence1.length();i++)
        {
            if(sentence1[i]==' ')
            {
                arr.push_back(temp);
                temp="";
            }else{
                temp+=sentence1[i];
            }
        }
        arr.push_back(temp);
        temp="";
        vector<string> another;
        for(int i=0;i<sentence2.length();i++)
        {
              if(sentence2[i]==' ')
              {
                  another.push_back(temp);
                  temp="";
              }else{
                temp+=sentence2[i];
              }
        }
        another.push_back(temp);
        if(arr.size() < another.size())
        {
              swap(arr,another); 
        }
               int i=0,j=arr.size()-1;
               int k=0,l=another.size()-1;
                   while(i <=j and k <= l and arr[i] == another[k])
                   {
                       k++;
                       i++;
                   }
                   if(k > l)return true;
                   while(i <= j and k <= l and arr[j] == another[l])
                   {
                       l--;j--;
                   }
                   if(k > l)return true;
                   return false;
                   
               
        

    }
};