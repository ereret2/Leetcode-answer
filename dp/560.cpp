class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int n = nums.size(), res = 0, pre = 0;

        map[0] = 1;
        for (int i = 0; i < n; i++) {
            pre += nums[i];
            if (map.find(pre - k) != map.end())
                res += map[pre - k];
            map[pre]++;
        }
        return res;
    }
};