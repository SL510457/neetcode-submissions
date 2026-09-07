class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(rightHeap.empty()) 
            rightHeap.push(num);
        else if(num < rightHeap.top())
            leftHeap.push(num);
        else
            rightHeap.push(num);

        // 1 1 or 1 2 -> 2 1 or 1 3
        if(leftHeap.size() > rightHeap.size()) {
            rightHeap.push(leftHeap.top());
            leftHeap.pop();
        }
        else if(rightHeap.size() - leftHeap.size() > 1){
            leftHeap.push(rightHeap.top());
            rightHeap.pop();
        }
        
            
    }
    
    double findMedian() {
        if(leftHeap.size() < rightHeap.size()) return rightHeap.top();
        return ((double)leftHeap.top()+(double)rightHeap.top())/2;

        // only same or right larger
    }

    private:
        priority_queue<int> leftHeap;
        priority_queue<int, vector<int>, greater<int>> rightHeap; 
};
