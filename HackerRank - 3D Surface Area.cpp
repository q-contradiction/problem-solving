/* 
 * Problem: www.hackerrank.com/challenges/3d-surface-area/problem
 *
 * The algorith calculates how much the stack of cubes in (i,j) contributes to the total area.
 * Since A(i,j) > 0, there will be at least one cube, and the area (down & up) is standard 2 
 * For the rest areas, we check if (i,j) is in the inner or outer part of the 2D
 * In the outer part calculation is straightforward
 * In the inner part the area is the difference of the current Aij - next Aij
 */

int surfaceArea(vector<vector<int>> A) {

    int area = 0, col,row, area_left, area_right, area_front, area_back, area_downandup;

    for (row = 0; row < A.size(); ++row){
        for (col = 0; col < A[0].size(); ++col){
            
            area_downandup = 2;
                        
            if (row-1 >= 0)
                area_left = (A[row][col]>A[row-1][col]) ? (A[row][col]-A[row-1][col]) : 0;
            else
                area_left = A[row][col];

            if (row+1 < A.size())
                area_right = (A[row][col]>A[row+1][col]) ? (A[row][col]-A[row+1][col]) : 0;
            else
                area_right = A[row][col];
            
            if (col-1 >= 0)
                area_front = (A[row][col]>A[row][col-1]) ? (A[row][col]-A[row][col-1]) : 0;
            else 
                area_front = A[row][col];
            
            if (col+1 < A[0].size())
                area_back = (A[row][col]>A[row][col+1]) ? (A[row][col]-A[row][col+1]) : 0;
            else 
                area_back = A[row][col];

            area += area_downandup + area_back + area_front + area_left + area_left;
        
        }
    }

    return area;
}
