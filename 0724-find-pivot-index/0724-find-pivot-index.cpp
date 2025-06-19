class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n= nums.size();
        int totalsum =0;
        for(int i=0;i<n;i++){
            totalsum +=nums[i];
        }
        int Prefixsum =0;
        for(int i=0;i<n;i++){
            int suffixsum = totalsum - Prefixsum - nums[i];
            if(suffixsum == Prefixsum){
                return i;
            }
            Prefixsum += nums[i];
        }
        return -1;
    }
};