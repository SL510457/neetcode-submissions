class MedianFinder {
public:
    void addNum(int num) {
        if(rightHeap.empty() || num > rightHeap.top()) 
            rightHeap.push(num);
        else
            leftHeap.push(num);

        if(leftHeap.size() > rightHeap.size()) {
            rightHeap.push(leftHeap.top());
            leftHeap.pop();
        }
        else if(rightHeap.size() > leftHeap.size() + 1){
            leftHeap.push(rightHeap.top());
            rightHeap.pop();
        }
        
            
    }
    
    double findMedian() {
        if(leftHeap.size() < rightHeap.size()) 
            return rightHeap.top();
        
        return ((double)leftHeap.top()+(double)rightHeap.top())/2;

    }

    private:
        priority_queue<int> leftHeap;
        priority_queue<int, vector<int>, greater<int>> rightHeap; 
};
