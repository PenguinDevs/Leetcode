/*
 * @lc app=leetcode id=2402 lang=cpp
 *
 * [2402] Meeting Rooms III
 * 
 * NOTE: Don't be afraid to use long long
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> roomUses(n);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> roomVacantFrom;
        priority_queue<int, vector<int>, greater<int>> vacantRooms;
        for (int i {0}; i < n; ++i) roomVacantFrom.push({0LL, i});

        sort(meetings.begin(), meetings.end());

        for (const auto& timeBlock : meetings) {
            long long startTime = timeBlock[0];
            long long endTime = timeBlock[1];
            // Free up rooms that have become vacant by startTime
            while (!roomVacantFrom.empty() && roomVacantFrom.top().first <= startTime) {
                vacantRooms.push(roomVacantFrom.top().second);
                roomVacantFrom.pop();
            }
            int roomId;
            if (!vacantRooms.empty()) {
                roomId = vacantRooms.top();
                vacantRooms.pop();
                roomVacantFrom.push({endTime, roomId});
            } else {
                // All rooms occupied, wait for the earliest one to be free
                auto [vacantFrom, id] = roomVacantFrom.top();
                roomVacantFrom.pop();
                roomId = id;
                roomVacantFrom.push({vacantFrom + (endTime - startTime), roomId});
            }
            ++roomUses[roomId];
            // cout << "assigned room " << roomId << " to start time " << startTime << " ending at " << endTime << endl;
        }

        // for (int i {0}; i < roomUses.size(); ++i) cout << i << " " << roomUses[i] << endl;

        int maxUsedRoom {-1};
        int maxUses {0};
        for (int i {0}; i < roomUses.size(); ++i) {
            if (roomUses[i] > maxUses) {
                maxUsedRoom = i;
                maxUses = roomUses[i];
            }
        }

        return maxUsedRoom;
    }
};
// @lc code=end

