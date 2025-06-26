class Solution {
public:

    bool isIsomorphic(string s1, string s2) {
        unordered_map<char,char> map1;
        unordered_map<char,char>map2;
    if(s1.size()!=s2.size()) return false;
        for(int i=0;i<s1.size();i++){
            if(map1.find(s1[i]) != map1.end()){  // yha check kr rahe hai ki agar map mai s1[i] present hai ya nahi
                if(map1[s1[i]] != s2[i]){  // yha check kr rahe hai ki agar map mai s1[i] ka value s2[i] ke barabar hai nhi 
                    return false;
                }
            }else{
                map1[s1[i]]=s2[i]; 
            }
            // check for s2 to s1 (visa-versa)
            if(map2.find(s2[i])!=map2.end()){
                if(map2[s2[i]] != s1[i]){
                    return false;
                }
            }else{
                map2[s2[i]] = s1[i];
            }
        }
        return true;
    }
};