class Solution {
public:
    int bitwiseComplement(int N) {
        if (N == 0)
            return 1;
        int n = 0, tmp = N;
        while (tmp != 0)
        {
            tmp >>= 1;
            n <<= 1;
            n += 1;
        }
        //cout << "n:" << n << endl;
        return n ^ N;
    }
};