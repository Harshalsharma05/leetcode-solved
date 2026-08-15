class KthLargest {
    int num; // to hold k
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    KthLargest(int k, vector<int>& nums) {
        num = k;
        for(auto ele : nums) {
            minHeap.push(ele);
            if(minHeap.size() > k) minHeap.pop(); // always maintain k largest elements in the pq
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size() > num) minHeap.pop();
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */