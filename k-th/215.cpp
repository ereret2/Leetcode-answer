class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return quickSelect(nums, 0, n - 1, n - k);
    }

    int quickSelect(vector<int>& nums, int left, int right, int k) {
        if (left == right)
            return nums[left];
        int index = partition(nums, left, right);

        if (index == k)
            return nums[index];
        else {
            if (index > k)
                return quickSelect(nums, left, index - 1, k);
            else
                return quickSelect(nums, index + 1, right, k);
        }
        return 0;
    }

    void swap(int &a, int &b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right];
        int index = left;
        for (int i = left; i < right; i++) {
            if (nums[i] < pivot) {
                swap(nums[index], nums[i]);
                index++;
            }
        }

        swap(nums[right], nums[index]);
        return index;
    }
};