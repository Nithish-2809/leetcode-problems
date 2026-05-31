class Twitter {
public:
    vector<pair<int,int>> tweets;
    unordered_map<int, unordered_set<int>> followMap;

    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets.push_back({userId, tweetId});
    }

    vector<int> getNewsFeed(int userId) {

        vector<int> feed;

        for(int i = (int)tweets.size() - 1; i >= 0; i--) {

            int author = tweets[i].first;
            int tweetId = tweets[i].second;

            if(author == userId ||
               followMap[userId].count(author)) {

                feed.push_back(tweetId);

                if(feed.size() == 10)
                    break;
            }
        }

        return feed;
    }

    void follow(int followerId, int followeeId) {
        if(followerId != followeeId)
            followMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};