class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> heap; // max
        
        for(auto ele : stones) {
            heap.push(ele);
        }

        while(heap.size() > 1) {
            int f = heap.top();
            heap.pop();
            int s = heap.top();
            heap.pop();

            if((f - s) > 0) heap.push(f-s); 
        }

        if(heap.size() == 1) return heap.top();

        return 0;
    }
};