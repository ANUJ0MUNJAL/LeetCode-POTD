class Solution {
public:
    bool hasMatch(string s, string p) {
        if(p[0]=='*')
        {
            if(s.find(p.substr(1,p.length()-1)) != -1)return true;
            return false;
        }
        if(p[p.length()-1]=='*')
        {
            if(s.find(p.substr(0,p.length()-1))!=-1)return true;
            return false;
        }
        int index = p.find('*');
        string a = p.substr(0,index);
        if(s.find(a) == -1)return false;
        index = s.find(a);
        index+=a.length();
        
        string temp = s.substr(index);
        // cout<<temp<<endl;
        a = p.substr(p.find('*')+1);
        // cout<<a<<endl;
        if(temp.find(a)!=-1)return true;
        return false;
    }
};