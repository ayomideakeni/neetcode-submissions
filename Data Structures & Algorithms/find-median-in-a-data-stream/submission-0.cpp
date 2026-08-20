class MedianFinder {
public:
    priority_queue<int, vector<int>,greater<>> big;
    priority_queue<int> small;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        small.push(num);
        if((!big.empty() && big.top() < small.top())){
            int carry = small.top();
            small.pop();
            big.push(carry);
        }
        if(small.size() > big.size() + 1){
            int carry = small.top();
            small.pop();
            big.push(carry);
        }else if(big.size() > small.size() + 1){
            int carry = big.top();
            big.pop();
            small.push(carry);
        }
    }
    
    double findMedian() {
        size_t minSize = small.size();
        size_t maxSize = big.size();
        if(minSize == maxSize){
            
            double mid = small.top() + big.top();
            double median = (mid / 2);
            return median;
        }else{
            if(minSize < maxSize) return big.top();
            else return small.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */