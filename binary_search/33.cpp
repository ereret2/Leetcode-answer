class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0)
            return -1;
        int minIndex = findMinIndex(nums);
        int resIndex = binarySearch(nums, 0, minIndex - 1, target);
        if (resIndex == -1)
            resIndex = binarySearch(nums, minIndex, n - 1, target);
        return resIndex;
    }

    int findMinIndex(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1, mid;
        while (left < right) {
            mid = left + (right - left) / 2;

            if (mid > left && nums[mid] < nums[mid - 1])
                return mid;
            if (mid < right && nums[mid + 1] < nums[mid])
                return mid + 1;
            if (nums[mid] < nums[right])
                right = mid - 1;
            else
                left = mid + 1;
        }
        return 0;
    }

    int binarySearch(vector<int>& nums, int left, int right, int target) {
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        if (nums[left] != target)
            return -1;
        return left;
    }
};