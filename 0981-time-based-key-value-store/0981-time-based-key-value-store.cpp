class TimeMap {
public:
    TimeMap() {
        
    }
    unordered_map<string, vector<pair<int, string>>> keyBasedMap;
    void set(string key, string value, int timestamp) {
        keyBasedMap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = keyBasedMap.find(key);
        if(it == keyBasedMap.end()){
            return "";
        }
        vector<pair<int, string>>& entries = it->second;
        int low = 0;
        int high = entries.size() - 1;
        int resIndex = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(entries[mid].first <= timestamp) {
                resIndex = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        if(resIndex == -1) {
            return "";
        }
        else {
            return entries[resIndex].second;
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */