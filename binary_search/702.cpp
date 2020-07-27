/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int right = 1;
        while (reader.get(right) < target)
        {
            right *= 2;
        }

        int left = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (reader.get(mid) == target)
                return mid;
            if (reader.get(mid) > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        if (reader.get(left) != target)
            return -1;
        return left;
    }
};