class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int m = baskets.size();
        int placed = 0;
        for(int i = 0; i<n;i++){
            for(int j =0;j<m;j++){
                if(baskets[j] >= fruits[i]){
                    baskets[j] = -1;
                    placed++;
                    break; // Move to the next fruit after placing it in a basket
                }
            }
        }
        return n - placed; // Return the number of unplaced fruits
    }
};