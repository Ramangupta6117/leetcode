class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        int n = arr.size();
    int st = 0, end = n - 1;
    int first = -1, last = -1;

    // Find first occurrence
    while (st <= end) {
        int mid = st + (end - st) / 2;
        if (arr[mid] == target) {
            first = mid;
            end = mid - 1; // keep searching in the left half
        } else if (arr[mid] < target) {
            st = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    st = 0;
    end = n - 1;

    // Find last occurrence
    while (st <= end) {
        int mid = st + (end - st) / 2;
        if (arr[mid] == target) {
            last = mid;
            st = mid + 1; // keep searching in the right half
        } else if (arr[mid] < target) {
            st = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return {first, last};
    }
};