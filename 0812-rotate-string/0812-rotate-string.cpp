class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        int m = goal.size();
        if(n != m) return false;
        string doubled = s + s;
        //return doubled.find(goal) != string::npos;
        for (int i = 0; i < s.length(); i++) {
            string rotated = doubled.substr(i, s.length());
            if (rotated == goal) {
                return true;
            }
        }
        return false;
    }
};