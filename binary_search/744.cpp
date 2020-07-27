class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();

        int isBiggerThanBiggest = compareLetter(target, letters[n - 1]);
        if (compareLetter(target, letters[n - 1]) >= 0 || compareLetter(target, letters[0]) == -1)
            return letters[0];

        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (compareLetter(target, letters[mid]) < 0)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return letters[left % n];
    }

    int compareLetter(char tmp, char target) {
        if (tmp - target > 0)
            return 1;
        else if (tmp - target == 0)
            return 0;
        else
            return -1;
    }
};