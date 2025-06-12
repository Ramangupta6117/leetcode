class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> len(n, 1); // Step 1: Initialize all lengths to 1

        // Step 2: Try to build LIS ending at each index
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    len[i] = max(len[i], len[j] + 1);
                }
            }
        }

        // Step 3: Find the maximum value in len[]
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, len[i]);
        }

        return ans;
    }
};