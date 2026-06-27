class Solution {
public:
    bool BSInARow(vector<vector<int>>& matrix, int target,int targetRow){
        int column = matrix[0].size();
        int low = 0;
        int high = column-1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(target == matrix[targetRow][mid]){
                return true;
            }
            else if(target < matrix[targetRow][mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return false;
    }


    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int column = matrix[0].size();
        //binary search approuch to find the row that contain the target
        int startRow = 0;
        int endRow = row - 1;
        while(startRow <= endRow){
            int midRow = startRow + (endRow - startRow) / 2;
            if(target >= matrix[midRow][0] && target <= matrix[midRow][column-1]){
                return BSInARow(matrix,target,midRow);
            }
            else if(target < matrix[midRow][0]){
                endRow = midRow - 1;
            }
            else{
                startRow = midRow + 1;
            }
        }
        return false;
    }
    
};