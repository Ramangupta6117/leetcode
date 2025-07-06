class FindSumPairs {
public:
vector<int>nums1;
vector<int>nums2;
unordered_map<int,int>m;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        
        this->nums1 = nums1;
        this->nums2 = nums2;
        for(int i =0;i<nums2.size();i++){
            m[nums2[i]]++;
        }
    }
    
    void add(int index, int val) {
        int orignal = nums2[index];
        m[orignal]--;
        nums2[index] +=val;
        m[nums2[index]]++;
    }
    
    int count(int tot) {
        int result = 0;

        for (int num1 : nums1) {
            int target = tot - num1;
            if (m.count(target)) {
                result += m[target];
            }
        }

        return result;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */