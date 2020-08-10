class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            count[nums[i]]++;
        }
        priority_queue<pair<int, int>> tmp;
        for (auto it = count.begin(); it != count.end(); it++)
        {
            tmp.push(pair<int, int>(it->second, it->first));
        }
        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back(tmp.top().second);
            tmp.pop();
        }
        return res;
    }
};