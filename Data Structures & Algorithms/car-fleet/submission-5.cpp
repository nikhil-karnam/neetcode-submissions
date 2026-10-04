class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::vector<std::pair<double, double>> dt;
        for(int i = 0; i < speed.size(); i++){
            dt.push_back({position[i], (double)(target-position[i])/speed[i]});
        }
        
        std::sort(dt.begin(), dt.end());
        
        int res = 0;
        int i = speed.size() - 1;
        while(i >= 0){
            //start a new fleat
            res++;
            double leader = dt[i].second;
            //start checking from the one before the leader
            i--;
            while(i >= 0 && dt[i].second <= leader){
                i--;
            }
        }

        return res;
    }
};
