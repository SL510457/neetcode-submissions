class Twitter {
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({postTime, tweetId});
        postTime--;
    }
    
    vector<int> getNewsFeed(int userId) {
        set<pair<int,int>> recent;
        for(auto f:followers[userId]) {
            for(auto t : tweets[f]) {
                recent.insert(t);
            }
        }
        for(auto t : tweets[userId])
            recent.insert(t);
        vector<int> posts;
        for(int i = 0; i < 10; i++) {
            if(!recent.empty()) {
                posts.push_back((*recent.begin()).second);
                recent.erase(recent.begin());
            }
            else 
                break;
        }

        return posts;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
    
    private:
        unordered_map<int, unordered_set<int>> followers;
        int postTime = 0;
        unordered_map<int, vector<pair<int,int>>> tweets;
    
};
