class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>map;
        int sum = 0;
        map[0] = -1; 
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            if(k != 0) {
                sum = sum % k;
            }
            if(map.find(sum) != map.end()) {
                if(i - map[sum] > 1) { 
                    return true;
                }
            } else {
                map[sum] = i; 
            }
    }
        return false;
    }
};