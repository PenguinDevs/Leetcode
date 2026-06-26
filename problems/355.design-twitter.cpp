/*
 * @lc app=leetcode id=355 lang=cpp
 *
 * [355] Design Twitter
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Twitter {
    const int MAX_FEED_SIZE = 10;

    int globalPostCount {0};
    unordered_map<int, unordered_set<int>> follows;
    unordered_map<int, vector<pair<int, int>>> posts;

public:
    Twitter() = default;
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({++globalPostCount, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        struct FeedEntry {
            int time;
            int tweetId;
            int userId;
            int tweetIndex;

            bool operator<(const FeedEntry& other) const {
                return time < other.time;
            }
        };

        priority_queue<FeedEntry> feed;
        auto addLatestTweet = [&](int id) {
            auto it = posts.find(id);
            if (it == posts.end() || it->second.empty()) {
                return;
            }

            const int tweetIndex = static_cast<int>(it->second.size()) - 1;
            const auto& tweet = it->second[tweetIndex];
            feed.push({tweet.first, tweet.second, id, tweetIndex});
        };

        addLatestTweet(userId);
        const auto followIt = follows.find(userId);
        if (followIt != follows.end()) {
            for (int followeeId : followIt->second) {
                addLatestTweet(followeeId);
            }
        }

        vector<int> out;
        while (!feed.empty() && out.size() < MAX_FEED_SIZE) {
            const auto latestPost = feed.top();
            feed.pop();
            out.push_back(latestPost.tweetId);

            if (latestPost.tweetIndex > 0) {
                const auto& userTweets = posts[latestPost.userId];
                const int nextIndex = latestPost.tweetIndex - 1;
                const auto& tweet = userTweets[nextIndex];
                feed.push({tweet.first, tweet.second, latestPost.userId, nextIndex});
            }
        }

        return out;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            follows[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        const auto it = follows.find(followerId);
        if (it != follows.end()) {
            it->second.erase(followeeId);
            if (it->second.empty()) {
                follows.erase(it);
            }
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// @lc code=end

