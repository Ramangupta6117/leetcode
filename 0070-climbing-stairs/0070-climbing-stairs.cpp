class Solution {
public:
    int climbStairs(int n) {
        int prev = 0, cur = 1;
        while (n--) {
            int next = cur + prev;
            prev = cur;
            cur = next;
        }
        return cur;
    }
};