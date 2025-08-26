class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxdiagonal = 0.0;
        int maxArea = 0;

        for(int i =0; i<dimensions.size();i++){
            int length = dimensions[i][0];
            int width = dimensions[i][1];

            double diag = sqrt(length * length + width * width);
            int area = width * length;
            if(diag > maxdiagonal){
                maxdiagonal = diag;
                maxArea = area;
            }else if(diag == maxdiagonal && area > maxArea){
                maxArea = area;
            }
        }
        return maxArea;
    }
};