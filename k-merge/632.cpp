class Solution {
public:
    struct valueCompare {
        bool operator()(const pair<int, pair<int, int>> &x, const pair<int, pair<int, int>> &y)        {
            return x.first > y.first;
        }
    };

    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, valueCompare> minHeap;

        int n = nums.size();
        int rangeStart = -100000, rangeEnd = 100000, currentMaxNumber = -100001;
        for (int i = 0; i < n; i++) {
            minHeap.push(make_pair(nums[i][0], make_pair(i, 0)));
            currentMaxNumber = max(currentMaxNumber, nums[i][0]);
        }

        while (minHeap.size() == n) {
            auto tmp = minHeap.top();
            minHeap.pop();

            int currentMinNumber = tmp.first;
            int listIndex = tmp.second.first;
            int valueIndex = tmp.second.second;
            if (rangeEnd - rangeStart > currentMaxNumber - currentMinNumber){
                rangeEnd = currentMaxNumber;
                rangeStart = currentMinNumber;
            }

            valueIndex++;
            if (nums[listIndex].size() > valueIndex) {
                minHeap.push(make_pair(nums[listIndex][valueIndex], make_pair(listIndex,                        valueIndex)));
                currentMaxNumber = max(nums[listIndex][valueIndex], currentMaxNumber);
            }
        }
        return {rangeStart, rangeEnd};
    }
};