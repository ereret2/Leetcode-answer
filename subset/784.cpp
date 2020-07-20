class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        int n = S.size();
        vector<string> permutation;

        if (n == 0)
            return permutation;

        permutation.push_back(S);
        for (int i = 0; i < n; i++) {
            if (isalpha(S[i])) {
                int m = permutation.size();
                for (int j = 0; j < m; j++) {
                    vector<char> chs(permutation[j].begin(), permutation[j].end());
                    if (isupper(chs[i])) {
                        chs[i] = tolower(chs[i]);
                    }
                    else {
                        chs[i] = toupper(chs[i]);
                    }
                    permutation.push_back(string(chs.begin(), chs.end()));
                }
                
            }
            
        }
        return permutation;
    }
};