// class Solution {
// public:
//     vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//         vector<vector<int>> ans;

//         for (int i = 0; i < points.size(); i++) {
//             int dist =
//                 (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);

//             pq.push({dist, i});
//         }

//         while (k != 0) {
//             int idx = pq.top().second;
//             pq.pop();
//             ans.push_back(points[idx]);
//             k--;
//         }

//         return ans;
//     }
// };

// using max heap
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> maxHeap;
        for (auto& point : points) {
            int dist = point[0] * point[0] + point[1] * point[1];
            maxHeap.push({dist, {point[0], point[1]}});
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        vector<vector<int>> res;
        while (!maxHeap.empty()) {
            res.push_back({maxHeap.top().second.first,
                           maxHeap.top().second.second});
            maxHeap.pop();
        }
        return res;
    }
};