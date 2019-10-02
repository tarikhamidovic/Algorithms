#include <iostream> 
#define UNASSIGNED 0  
#define N 9  

bool FindUnassignedLocation(int grid[N][N], int &row, int &col);  

bool isSafe(int grid[N][N], int row, int col, int num);

bool SolveSudoku(int grid[N][N]) {  
  int row, col;  
  if (!FindUnassignedLocation(grid, row, col))  
    return true; 
  for (int num = 1; num <= 9; num++) {  
    if (isSafe(grid, row, col, num)) {  
      grid[row][col] = num;  
      if (SolveSudoku(grid))  
        return true;  
      grid[row][col] = UNASSIGNED;  
    }  
  }  
  return false;   
}  
  
bool FindUnassignedLocation(int grid[N][N], int &row, int &col) {  
  for (row = 0; row < N; row++)  
    for (col = 0; col < N; col++)  
      if (grid[row][col] == UNASSIGNED)  
        return true;  
  return false;  
}  
  
bool UsedInRow(int grid[N][N], int row, int num) {  
  for (int col = 0; col < N; col++)  
    if (grid[row][col] == num)  
      return true;  
  return false;  
}  
  
bool UsedInCol(int grid[N][N], int col, int num) {  
  for (int row = 0; row < N; row++)  
    if (grid[row][col] == num)  
      return true;  
  return false;  
}  
  
bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num) {  
  for (int row = 0; row < 3; row++)  
    for (int col = 0; col < 3; col++)  
      if (grid[row + boxStartRow][col + boxStartCol] == num)  
        return true;  
  return false;  
}  
  
bool isSafe(int grid[N][N], int row, int col, int num) {  
  return !UsedInRow(grid, row, num) && !UsedInCol(grid, col, num) && !UsedInBox(grid, row - row % 3, col - col % 3, num) && grid[row][col] == UNASSIGNED;  
}  
  
void printGrid(int grid[N][N]) {  
  for (int row = 0; row < N; row++) {  
    for (int col = 0; col < N; col++)  
      std::cout << grid[row][col] << " ";  
    std::cout << std::endl; 
  }  
}  
  
int main() {  
  int grid[N][N] = { {5, 3, 0, 0, 7, 0, 0, 0, 0},
                     {6, 0, 0, 1, 9, 5, 0, 0, 0},  
                     {0, 9, 8, 0, 0, 0, 0, 6, 0},  
                     {8, 0, 0, 0, 6, 0, 0, 0, 3},  
                     {4, 0, 0, 8, 0, 3, 0, 0, 1},  
                     {7, 0, 0, 0, 2, 0, 0, 0, 6},  
                     {0, 6, 0, 0, 0, 0, 2, 8, 0},  
                     {0, 0, 0, 4, 1, 9, 0, 0, 5},  
                     {0, 0, 0, 0, 8, 0, 0, 7, 9} };

  if (SolveSudoku(grid) == true)  
    printGrid(grid);  
  else
    std::cout << "No solution exists";  
  return 0;  
}  
  
