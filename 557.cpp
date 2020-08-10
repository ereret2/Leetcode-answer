class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string res = "", tmp = "";
        int index = 0;
        while (index < n) {
            if (s[index] != ' ' && index != n - 1) {
                tmp += s[index];
            }
            else if (index == n - 1) {
                tmp += s[index];
                int size_tmp = tmp.size();
                for (int i = 0; i < size_tmp; i++)
                    res += tmp[size_tmp - i - 1];
                tmp = "";
            }
            else {
                int size_tmp = tmp.size();
                for (int i = 0; i < size_tmp; i++)
                    res += tmp[size_tmp - i - 1];
                res += ' ';
                tmp = "";
            }
            index++;
        }

        return res;
    }
};