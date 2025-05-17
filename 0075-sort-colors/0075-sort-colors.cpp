class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size()-1;

        int low = 0;
        int high = n;
        int mid = 0;

        while(mid<=high){
            if(nums[mid]==0){
            swap(nums[low],nums[mid]);
            low++;
            mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
               swap(nums[high],nums[mid]);
                high--;
        }
        }
    }
};