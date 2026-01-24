class AuctionSystem {
public:
    AuctionSystem() {
        
    }
    map<int,set<pair<int,int>>> mp;
    map<pair<int,int>,int> mp1;
    void addBid(int userId, int itemId, int bidAmount) {
        if(mp1.count({userId,itemId}) > 0)
        {
            int value = mp1[{userId,itemId}];
            mp[itemId].erase(mp[itemId].find({value,userId}));
            mp[itemId].insert({bidAmount,userId});
        }else{
          mp[itemId].insert({bidAmount,userId});
        }
        mp1[{userId,itemId}] = bidAmount;
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
         int value = mp1[{userId,itemId}];
          mp[itemId].erase(mp[itemId].find({value,userId}));
          mp[itemId].insert({newAmount,userId});
          mp1[{userId,itemId}] = newAmount;
    }
    
    void removeBid(int userId, int itemId) {
        int value = mp1[{userId,itemId}];
        mp[itemId].erase(mp[itemId].find({value,userId}));
        mp1.erase({userId,itemId});
    }
    
    int getHighestBidder(int itemId) {
       
        if(mp[itemId].size() <= 0)return -1;
        return mp[itemId].rbegin()->second;
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */