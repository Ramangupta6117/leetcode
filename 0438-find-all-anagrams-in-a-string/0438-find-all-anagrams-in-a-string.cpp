class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        int i=0,j=0;
        vector<int> result;
        unordered_map<char,int> map;
        while(j<n){
            map[s[j]]++;
            if(j-i+1 < m){
                j++;
            }
            else if(j-i+1==m){
                unordered_map<char,int> map2;
                for(int k=0;k<m;k++){
                    map2[p[k]]++;
                }
                if(map==map2){
                    result.push_back(i);
                }
                map[s[i]]--;
                if(map[s[i]] == 0) {  
                    map.erase(s[i]);
                }
                i++; 
                j++;
            }
        }
        return result;
    }
};