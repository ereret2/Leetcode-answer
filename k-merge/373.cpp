class Solution {
public:
    struct valueCompare {
        bool operator()(const pair<int, pair<int, int>> &x, const pair<int, pair<int, int>> &y)        {
            return x.first < y.first;
        }
    };

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        int size_nums1 = nums1.size(), size_nums2 = nums2.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, valueCompare> max_heap;

        for (int i = 0; i < size_nums1 && i < k; i++) {
            for (int j = 0; j < size_nums2 && j < k; j++) {
                if (max_heap.size() < k) {
                    max_heap.push(make_pair(nums1[i] + nums2[j], 
                    make_pair(nums1[i], nums2[j])));
                }
                else {
                    auto tmp = max_heap.top();
                    if (nums1[i] + nums2[j] >= tmp.first)
                        break;
                    else {
                        max_heap.pop();
                        max_heap.push(make_pair(nums1[i] + nums2[j], 
                    make_pair(nums1[i], nums2[j])));
                    }
                }
            }
        }
        while (!max_heap.empty()) {
            auto tmp = max_heap.top();
            max_heap.pop();
            res.push_back({tmp.second.first, tmp.second.second});

        }
        return res;
    }
};