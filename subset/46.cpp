class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        queue<vector<int>> queue;

        queue.push(vector<int>());
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int sizeOfQueue = queue.size();
            while (sizeOfQueue--) {
                vector<int> oldPermu = queue.front();
                queue.pop();

                int m = oldPermu.size();
                for (int j = 0; j <= m; j++) {
                    vector<int> newPermu(oldPermu);
                    newPermu.insert(newPermu.begin() + j, nums[i]);

                    if (newPermu.size() == n) {
                        res.push_back(newPermu);
                    }
                    else {
                        queue.push(newPermu);
                    }
                }
            }
            
        }
        return res;
    }
};