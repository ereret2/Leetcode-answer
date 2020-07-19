class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subsets;

        vector<int> empty;
        subsets.push_back(empty);

        int n = nums.size();
        int m = subsets.size();
        int startIndex = 0, endIndex = 0;
        for (int i = 0; i < n; i++) {
            startIndex = 0;

            if (i > 0 && nums[i] == nums[i - 1]) {
                startIndex = endIndex + 1;
            }
            endIndex = subsets.size() - 1;
            for (int j = startIndex; j <= endIndex; j++) {
                vector<int> tmp = vector(subsets[j]);
                tmp.push_back(nums[i]);
                subsets.push_back(tmp);
            }
        }

        return subsets;
    }
};