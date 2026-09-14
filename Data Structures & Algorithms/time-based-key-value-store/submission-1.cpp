class TimeMap {
public:
    struct Value{
        std::string value;
        int timestamp;
    };
    
    std::unordered_map<std::string, std::vector<Value>> m;
    
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        int low = 0;
        int high = m[key].size() - 1;
        while(low < high){
            int mid = (low + high + 1) / 2;
            if(m[key][mid].timestamp <= timestamp){
                low = mid;
            }
            else{
                high = mid - 1;
            }
        }
        if(m[key].size() == 0 || m[key][low].timestamp > timestamp){
            return "";
        }
        return m[key][low].value;
    }
};
