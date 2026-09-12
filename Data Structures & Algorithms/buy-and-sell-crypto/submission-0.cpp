class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = 1e9;
        int profit = 0;
        for(auto p : prices){
            min_price = std::min(min_price, p);
            //if i'm selling, i want to have bought it for the least price so far.
            if(p - min_price > profit){
                profit = p - min_price;
            }
        }
        return profit;
    }
};
