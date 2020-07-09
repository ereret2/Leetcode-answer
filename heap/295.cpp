class MedianFinder {
public:
    /** initialize your data structure here. */
    
    priority_queue<int, vector<int>, greater<int> > min_heap;
    priority_queue<int> max_heap;
    int len;
    MedianFinder() {
        len = 0;
    }
    
    void addNum(int num) {
        len++;
        if (max_heap.empty() || num <= max_heap.top()) {
            max_heap.push(num);
        }
        else {
            min_heap.push(num);
        }

        if (max_heap.size() > min_heap.size() + 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        else if (min_heap.size() > max_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    double findMedian() {
        if (len % 2 == 0) {
            return (double)min_heap.top() / 2 + (double)max_heap.top() / 2;
        }
        else {
            return max_heap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */