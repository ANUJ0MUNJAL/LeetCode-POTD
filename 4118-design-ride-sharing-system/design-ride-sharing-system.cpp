class RideSharingSystem {
public:
    RideSharingSystem() {
        
    }
    queue<int> rider;
    queue<int> driver;
    void addRider(int riderId) {
        rider.push(riderId);
    }
    
    void addDriver(int driverId) {
        driver.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        if(rider.size() >= 1 and driver.size()>=1)
        {
            vector<int> temp =  {driver.front(),rider.front()};
            rider.pop();
            driver.pop();
            return temp;
        }
        return {-1,-1};
    }
    
    void cancelRider(int riderId) {
        vector<int> temp;
        while(!rider.empty())
        {
            if(rider.front() == riderId)rider.pop();
            else{
                temp.push_back(rider.front());
                rider.pop();
            }
        }
        for(int i=0;i<temp.size();i++)rider.push(temp[i]);
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */