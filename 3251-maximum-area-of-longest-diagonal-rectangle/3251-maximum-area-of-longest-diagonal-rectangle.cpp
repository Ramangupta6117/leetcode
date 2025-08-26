class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxDiagonal = 0.0;
int maxArea = 0;

for (int i = 0; i < dimensions.size(); i++) {
    int width = dimensions[i][0];
    int height = dimensions[i][1];

    double diagonal = sqrt(width * width + height * height);
    int area = width * height;

    if (diagonal > maxDiagonal) {
        maxDiagonal = diagonal;
        maxArea = area;
    } else if (diagonal == maxDiagonal && area > maxArea) {
        maxArea = area;
    }
}
return maxArea;
    }
};