class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int n = A.size();
        for (int i = 0; i < n; i++)
            reverse(A[i].begin(), A[i].end());

        int m = A[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                A[i][j] ^= 1;
            }
        }

        return A;
    }
};