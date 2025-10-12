class ExamTracker {
public:
    ExamTracker() {
        
    }
    vector<pair<long long,long long>> arr;
    
    void record(int time, int score) {
        if(arr.size() == 0)
        {
            arr.push_back({time,score});
        }else{
            arr.push_back({time,arr.back().second+score});
        }
    }
    
    long long totalScore(int startTime, int endTime) {
       
        auto right = upper_bound(arr.begin(),arr.end(),make_pair(endTime,1e18))-arr.begin();
        right--;
        auto left = lower_bound(arr.begin(),arr.end(),make_pair(startTime,0))-arr.begin();
        left--;
        if(right < 0)return 0;
        if(left < 0)
        {
            return arr[right].second;
        }
        return arr[right].second - arr[left].second;
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */