class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            vector<int> freq(26, 0); // freq arr
            for (char c : s) {
                freq[c - 'a']++;
            }

            // Convert frequency array to string key
            stringstream ss;
            for (int f : freq) {
                ss << f << "#";  // Use '#' to separate counts
            }
            string key = ss.str();

            // Insert into map
            mp[key].push_back(s);
        }

        // Collecting results
        vector<vector<string>> ans;
        for (auto& pair : mp) {
            ans.push_back(pair.second);
        }

        return ans;
    }
};