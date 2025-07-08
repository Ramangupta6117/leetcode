class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int n = height.size();
        vector<int> left(n), right(n);
        stack<int> stk;

        // Find index of previous smaller for each bar
        for(int i = 0; i < n; i++) {
            while(!stk.empty() && height[stk.top()] >= height[i]) {
                stk.pop();
            }
            if(stk.empty()) left[i] = -1;
            else left[i] = stk.top();
            stk.push(i);
        }

        // Clear stack for next use
        while(!stk.empty()) stk.pop();

        // Find index of next smaller for each bar
        for(int i = n-1; i >= 0; i--) {
            while(!stk.empty() && height[stk.top()] >= height[i]) {
                stk.pop();
            }
            if(stk.empty()) right[i] = n;
            else right[i] = stk.top();
            stk.push(i);
        }

        int maxA = 0;
        for(int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            maxA = max(maxA, height[i] * width);
        }
        return maxA;
    }
};
