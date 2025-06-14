class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        vector<int>missing;
        for(int i =0;i<n;i++){
            s.insert(nums[i]);
        }
        for(int i=1;i<=n;i++){
            if(s.find(i)==s.end()){
                missing.push_back(i);
            }
        }
        return missing;
    }
};