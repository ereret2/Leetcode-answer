class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += nums[i];

        if (sum % 2 == 1)
            return false;

        sum /= 2;
        vector<bool> dp(sum + 1, 0);
        dp[0] = true;
        for (int i = 0; i < n; i++) {
            for (int j = sum; j >= nums[i]; j--)
            {
                if (dp[sum])
                    return true;

                dp[j] = dp[j] | dp[j - nums[i]];
            }
        }
        return dp[sum];
    }
};