class Solution {
public:
    string mergeAlternately(string w1, string w2) {
        string res = "";
        int i = 0;
        while(i<w1.length() || i<w2.length()){
            if(i<w1.length()){
                res = res+w1[i];
            }
            if(i<w2.length()){
                res = res+w2[i];
            }
            i++;
        }
        return res;
    }
};