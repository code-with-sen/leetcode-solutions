// 2402. Meeting Rooms III [Hard]
// https://leetcode.com/problems/meeting-rooms-iii/
// Language: C++ | Runtime: 63 ms | Memory: 98.2 MB

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // Step 1: Sort meetings by start time
        sort(meetings.begin(), meetings.end());

        // Step 2: Free room heap (roomNumber)
        priority_queue<int, vector<int>, greater<int>> freeRooms;
        for (int i = 0; i < n; ++i) {
            freeRooms.push(i);
        }

        // Step 3: Occupied rooms heap: {endTime, roomNumber}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> usedRooms;

        // Step 4: Meeting count per room
        vector<int> roomCount(n, 0);

        for (auto& meet : meetings) {
            long long start = meet[0], end = meet[1];

            // Free up rooms whose meeting has ended
            while (!usedRooms.empty() && usedRooms.top().first <= start) {
                int room = usedRooms.top().second;
                usedRooms.pop();
                freeRooms.push(room);
            }

            // If no room is free, wait for the earliest one
            if (freeRooms.empty()) {
                auto [endTime, room] = usedRooms.top();
                usedRooms.pop();
                // Delay the meeting
                start = endTime;
                end = start + (meet[1] - meet[0]);
                freeRooms.push(room);
            }

            // Assign the meeting to the lowest-numbered free room
            int room = freeRooms.top();
            freeRooms.pop();

            usedRooms.push({end, room});
            roomCount[room]++;
        }

        // Step 5: Find room with maximum meetings
        int maxMeetings = 0, roomIndex = 0;
        for (int i = 0; i < n; ++i) {
            if (roomCount[i] > maxMeetings) {
                maxMeetings = roomCount[i];
                roomIndex = i;
            }
        }

        return roomIndex;
    }
};
