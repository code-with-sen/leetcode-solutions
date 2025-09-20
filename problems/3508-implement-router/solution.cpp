// 3508. Implement Router [Medium]
// https://leetcode.com/problems/implement-router/
// Language: C++ | Runtime: 168 ms | Memory: 413.6 MB

#include <bits/stdc++.h>
using namespace std;

class Router {
public:
    int memoryLimit;
    queue<array<int,3>> q; // FIFO: {source, destination, timestamp}
    unordered_set<long long> seen; // detect duplicates
    unordered_map<int, vector<int>> destMap; // destination -> sorted timestamps

    Router(int memoryLimit) {
        this->memoryLimit = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        long long key = ((long long)source << 40) ^ ((long long)destination << 20) ^ timestamp;
        if (seen.count(key)) return false;

        // If full, evict oldest
        if ((int)q.size() >= memoryLimit) {
            auto old = q.front(); q.pop();
            long long oldKey = ((long long)old[0] << 40) ^ ((long long)old[1] << 20) ^ old[2];
            seen.erase(oldKey);

            // remove from destMap
            auto &vec = destMap[old[1]];
            // oldest timestamp is always at the front for that destination
            vec.erase(vec.begin()); 
            if (vec.empty()) destMap.erase(old[1]);
        }

        q.push({source, destination, timestamp});
        seen.insert(key);
        destMap[destination].push_back(timestamp); // append (already increasing order)
        return true;
    }

    vector<int> forwardPacket() {
        if (q.empty()) return {};
        auto pkt = q.front(); q.pop();

        long long key = ((long long)pkt[0] << 40) ^ ((long long)pkt[1] << 20) ^ pkt[2];
        seen.erase(key);

        auto &vec = destMap[pkt[1]];
        // erase from front
        vec.erase(vec.begin());
        if (vec.empty()) destMap.erase(pkt[1]);

        return {pkt[0], pkt[1], pkt[2]};
    }

    int getCount(int destination, int startTime, int endTime) {
        if (!destMap.count(destination)) return 0;
        auto &vec = destMap[destination];
        auto it1 = lower_bound(vec.begin(), vec.end(), startTime);
        auto it2 = upper_bound(vec.begin(), vec.end(), endTime);
        return it2 - it1;
    }
};
