class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> res(2, -1);

        int l = binarySearch(nums, target, 1);
        if (l != -1) {
            res[0] = l;
            res[1] = binarySearch(nums, target, 0);
        }
        return res;
    }

    int binarySearch(vector<int>& nums, int target, int findMaxIndex)
    {
        int key = -1;
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                key = mid;
                if (findMaxIndex) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
        }
        return key;
    }
};