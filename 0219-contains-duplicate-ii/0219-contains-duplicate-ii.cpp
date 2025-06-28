class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& A, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < A.size(); ++i) {
            if (m.count(A[i]) && i - m[A[i]] <= k) return true;
            m[A[i]] = i;
        }
        return false;
    }
};