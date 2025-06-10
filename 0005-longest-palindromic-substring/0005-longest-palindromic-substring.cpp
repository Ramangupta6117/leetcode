class Solution {
public:
    string longestPalindrome(string s) {
        int N = s.size(), start = 0, len = 0;
        bool dp[1001] = {};
        for (int i = N - 1; i >= 0; --i) {
            for (int j = N - 1; j >= i; --j) {
                if (i == j) dp[j] = true;
                else dp[j] = s[i] == s[j] && (i + 1 > j - 1 || dp[j - 1]);
                if (dp[j] && j - i + 1 > len) {
                    start = i;
                    len = j - i + 1;
                }
            }
        }
        return s.substr(start, len);
    }
};