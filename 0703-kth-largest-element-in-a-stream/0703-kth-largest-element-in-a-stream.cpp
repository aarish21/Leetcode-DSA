class KthLargest {
public:
    int k;
    priority_queue <int, vector<int>, greater<int>> minHeap;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int x: nums){
            add(x);
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        while (minHeap.size()>k) minHeap.pop();
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */