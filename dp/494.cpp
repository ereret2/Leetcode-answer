class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += nums[i];

        if (sum < S || (S + sum) % 2 == 1)
            return 0;
        
        sum += S;
        sum /= 2;
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;
        if (nums[0] <= sum)
            dp[nums[0]] += 1;
        for (int i = 1; i < n; i++) {
            for (int j = sum; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[sum];

    }
};