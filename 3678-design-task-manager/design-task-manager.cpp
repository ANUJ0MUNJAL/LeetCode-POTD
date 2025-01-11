class TaskManager {
public:
    map<int,pair<int,int>> mp;
    set<pair<int,int>> st;
    TaskManager(vector<vector<int>>& tasks) {
        for(int i=0;i<tasks.size();i++)
        {
            mp[tasks[i][1]]={tasks[i][0],tasks[i][2]};
            st.insert({-1*tasks[i][2],-1*tasks[i][1]});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        mp[taskId]={userId,priority};
        st.insert({-1*priority,-1*taskId});
    }
    
    void edit(int taskId, int newPriority) {
        int val = mp[taskId].second;
        st.erase(st.find({-1*val,-1*taskId}));
        mp[taskId].second=newPriority;
        st.insert({-1*newPriority,-1*taskId});
        
    }
    
    void rmv(int taskId) {
        int val = mp[taskId].second;
        mp.erase(taskId);
        st.erase(st.find({-1*val,-1*taskId}));
    }
    
    int execTop() {
        if(st.size()==0)return -1;
        int priority = -1*st.begin()->first;
        int taskid = -1*st.begin()->second;
        st.erase(st.begin());
        return mp[taskid].first;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */