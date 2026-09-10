#include <unordered_map>
#include <unordered_set>
#include <vector>

class Twitter {
public:
    std::unordered_map<int, std::unordered_set<int>> following = {};
    std::vector<std::pair<int, int>> tweets;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        int count = 0;
        std::vector<int> tweet_ids;
        for(int i = tweets.size() - 1; i >= 0 && count < 10; i--){
            if(following[userId].count(tweets[i].first) || userId == tweets[i].first){
                count++;
                tweet_ids.push_back(tweets[i].second);
            }
        }
        return tweet_ids;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
