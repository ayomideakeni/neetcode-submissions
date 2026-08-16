class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int largestR = 0;
        stack<int> stack;
        heights.push_back(0);
        int width = 0;
        int length = 0;
        

        for(int i = 0; i < heights.size(); ++i){
                while(!stack.empty() && heights[i] < heights[stack.top()]){
                    if(stack.empty()) break;
                    int length = heights[stack.top()];
                    stack.pop();
                    int width = stack.empty() ? i : i - stack.top() -1 ;
                    largestR = max(largestR, (width * length));
                }
            stack.push(i);
            
        }
        return largestR;

    }
};