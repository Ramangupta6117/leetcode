class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int st =0;
        int end = n-1;
        int minval = nums[0];

        while(st <= end){
            int mid = st + (end-st)/2;
            if(nums[st] <= nums[mid]){ // if left part is sorted then we take st point as minimum;
                minval = min(minval,nums[st]);
                st = mid+1;
            }
            else{
                minval = min(minval,nums[mid]); // if right part is sorted then we take mid as minimum;
                end = mid -1;
            }
        }
        return minval;
    }
};