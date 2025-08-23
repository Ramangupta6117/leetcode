class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int maxR = 0;
        int currRange = 0;
        for(int i =0;i<nums.size()-1;i++){
            maxR = max(maxR,i+nums[i]);
            if(i==currRange){
                jumps++;
                currRange = maxR;
            }
        }
        return jumps;
    }
};