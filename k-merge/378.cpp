class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0], right = matrix[n - 1][n - 1];
        while (left < right)
        {
            int mid = (left + right) / 2;
            int cnt = search(matrix, mid);
            if (cnt < k)
                left = mid + 1;
            else
                right = mid;
        }
        return right;
    }

    int search(vector<vector<int>>& matrix, int target)
    {
        int n = matrix.size();
        int i = n - 1, j = 0;
        int cnt = 0;
        while (i >= 0 && j <= n- 1)
        {
            if (target < matrix[i][j])
            {
                i--;
            }
            else
            {
                cnt += i + 1;
                j++;
            }
        }
        return cnt;
    }
};