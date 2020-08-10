class KthLargest {
public:
    struct numCompare {
        bool operator()(const int &x, const int &y) { return x > y; }
    };

    priority_queue<int, vector<int>, numCompare> minHeap;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            add(nums[i]);
    }
    
    int add(int val) {
        minHeap.push(val);
        if ((int)minHeap.size() > K)
            minHeap.pop();
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */