#include <bits/stdc++.h>
using namespace std;
int N=9;
bool isSafe(int board[9][9], int row, 
					int col, int num)
{
	    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num || board[i][col] == num || board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num) {
            return false;
        }
    }
    return true;
}
bool solveSudoku(int grid[9][9], int row, int col)
{
	if (row == N - 1 && col == N)
		return true;
	if (col == N) {
		row++;
		col = 0;
	}
	if (grid[row][col] > 0)
		return solveSudoku(grid, row, col + 1);

	for (int num = 1; num <= N; num++) 
	{
		if (isSafe(grid, row, col, num)) 
		{
			grid[row][col] = num;
			if (solveSudoku(grid, row, col + 1))
				return true;
		}
		grid[row][col] = 0;
	}
	return false;
}
int main()
{
	int grid[9][9] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
					{ 5, 2, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 8, 7, 0, 0, 0, 0, 3, 1 },
					{ 0, 0, 3, 0, 1, 0, 0, 8, 0 },
					{ 9, 0, 0, 8, 6, 3, 0, 0, 5 },
					{ 0, 5, 0, 0, 9, 0, 6, 0, 0 },
					{ 1, 3, 0, 0, 0, 0, 2, 5, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 7, 4 },
					{ 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
  cout<<"The Solved sudoku"<<endl;

	if (solveSudoku(grid, 0, 0))

        for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j <N ; j++)
			cout << grid[i][j] << " ";
		cout << endl;
	}
	else
		cout << "4O4" << endl;
}
