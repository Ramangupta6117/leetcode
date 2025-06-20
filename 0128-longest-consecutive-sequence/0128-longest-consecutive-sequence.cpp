class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
    unordered_set<int>s;
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++){
        s.insert(arr[i]);
    }
    vector<int> v(s.begin(),s.end());
    sort(v.begin(),v.end());
    int Longest = 0;
    int n = v.size();
    for(int i=0;i<n;i++){
        int c = 1;
        int j = i;
        while(j>0 && j<n && v[j] - v[j-1]==1){
            c++;
            j++;
        }
        if(j!=i){
            i=j-1;
        }
        Longest = max(Longest,c);
    }
    return Longest;
    }
};