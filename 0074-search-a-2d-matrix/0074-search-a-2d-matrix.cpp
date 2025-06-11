class Solution {
public:
    bool search(vector<int>& arr,int target){
        int st = 0;
        int end = arr.size() - 1;
        while(st <= end){
            int mid = st + (end -st)/2;
            if(arr[mid] == target){
                return true;
            }
            else if(arr[mid] < target){
                st = mid+1;
            }
            else{
                end = mid -1;
            }
        }
        return false;
    }


    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        bool res = false;
        for(int i =0;i<n;i++){
            int m = matrix[i].size();
            if(target >= matrix[i][0] && target <= matrix[i][m-1]){
                res = search(matrix[i],target);
            }
            if(res == true){
                return res;
            }
        }
        return false;
    }
};