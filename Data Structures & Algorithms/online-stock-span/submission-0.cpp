class StockSpanner {
public:

    stack<pair<int,int>> s;
    StockSpanner() {
        
    }
    
    
    int next(int price) {
        int streak = 1;
        int newStreak = 0;
        while(!s.empty() && price >= s.top().first){
            newStreak += s.top().second;
            s.pop();
        }
        s.push({price,streak + newStreak});
        return streak + newStreak;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */