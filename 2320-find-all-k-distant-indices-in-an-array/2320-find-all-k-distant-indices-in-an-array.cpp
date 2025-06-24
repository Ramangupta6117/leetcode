class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
       int n = nums.size();
        set<int> s; 
        for(int i = 0; i < n; i++){
            if(nums[i] == key){
                int st = max(0, i - k);
                int end = min(n - 1, i + k);
                for(int j = st; j <= end; j++){
                    s.insert(j); 
                }
            }
        }
        vector<int> res(s.begin(), s.end()); 
        return res;
    }
};