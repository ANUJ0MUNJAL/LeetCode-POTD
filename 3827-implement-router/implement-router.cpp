class Router {
public:
    int size = 0;
    map<tuple<int,int,int>, int> mp;
    deque<vector<int>> dq;
    map<int,vector<int>> time;
    map<int,int> count;

    Router(int memoryLimit) {
        size = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        
        if(mp.find({source,destination,timestamp}) != mp.end())return false;
        dq.push_back({source,destination,timestamp});
        if(dq.size() > size){
            auto el = dq.front();
            // vector<int> temp = el;
            mp.erase({el[0],el[1],el[2]});
            
            dq.pop_front();
            count[el[1]]++;
            
        }
        mp[{source,destination,timestamp}]++;
        time[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if(dq.size() == 0)return {};
        auto el = dq.front();
        dq.pop_front();
        mp.erase({el[0],el[1],el[2]});
        count[el[1]]++;
        return el;
    }
  
    int getCount(int destination, int startTime, int endTime) {
        
         vector<int> &temp = time[destination];
         auto end = upper_bound(temp.begin()+count[destination],temp.end(),endTime)-temp.begin();
        
         auto start = lower_bound(temp.begin()+count[destination],temp.end(),startTime)-temp.begin();

        return end-start;       
        
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */