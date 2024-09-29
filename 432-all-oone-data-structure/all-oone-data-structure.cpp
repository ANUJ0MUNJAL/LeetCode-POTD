class AllOne {
public:
    AllOne() {
        
    }
    map<string,int> mp;
    set<pair<int,string>> st;
    void inc(string key) {
        if(mp.count(key)){
        mp[key]++;
        
        st.erase(st.find({mp[key]-1,key}));
        st.insert({mp[key],key});
        }else{
            mp[key]++;
            st.insert({1,key});
        }
    }
    
    void dec(string key) {
        mp[key]--;
        if(mp[key]==0)
        {
            st.erase({1,key});
            mp.erase(key);
        }else{
            st.erase({mp[key]+1,key});
            st.insert({mp[key],key});
        }
    
    }
    
    string getMaxKey() {
        if(st.size()==0)return "";
        return st.rbegin()->second;
    }
    
    string getMinKey() {
         if(st.size()==0)return "";
        return st.begin()->second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */