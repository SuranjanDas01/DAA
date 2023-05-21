//by SURANJAN DAS
#include <bits/stdc++.h>
using namespace std;

// Store all the possible answers
vector<vector<string> > answer;

// Print the board
void print_board()
{   //answer.size() has the total number of solutions
    for(int i=0;i<answer.size();i++){
        cout<<"Solution "<<i+1<<":\n";
	for (auto& str : answer[i]) {
		for (auto& letter : str)
			cout << letter << " ";
		cout << endl;
	}
    cout<<"\n\n";
    }
	return;
}
// We need to check in three directions
// 1. in the same column above the current position
// 2. in the left top diagonal from the given cell
// 3. in the right top diagonal from the given cell
int isSafe(int row, int col, vector<string>& board)
{
	for (int i = 0; i < board.size(); i++) {
		if (board[i][col] == 'Q')
			return false;
	}
	int i = row, j = col;
	while (i >= 0 && j >= 0)
		if (board[i--][j--] == 'Q')
			return false;
	i = row, j = col;
	while (i >= 0 && j < board.size())
		if (board[i--][j++] == 'Q')
			return false;
	return true;
}
// rec function here will fill the queens
// 1. there can be only one queen in one row
// 2. if we filled the final row in the board then row will
// be equal to total number of rows in board
// 3. push that board configuration in answer set because
// there will be more than one answers for filling the board
// with n-queens
void rec(vector<string> board, int row)
{
	if (row == board.size()) {
		answer.push_back(board);
		return;
	}
	for (int i = 0; i < board.size(); i++) {
		
		// For each position check if it is isSafe and if it
		// isSafe make a recursive call with
		// row+1,board[i][j]='Q' and then revert the change
		// in board that is make the board[i][j]='.' again to
		// generate more solutions
		if (isSafe(row, i, board)) {
			board[row][i] = 'Q';
			rec(board, row + 1);
			board[row][i] = '.';
		}
	}
	return;
}
// Function to solve n queens
vector<vector<string> > solveNQueens(int n)
{
	string s;
	for (int i = 0; i < n; i++)
		s += '.';
	
	// Vector of string will make our board which is
	// initially all empty
	vector<string> board(n, s);
	rec(board, 0);
	return answer;
}

// Driver code
int main()
{
	// size 4x4 is taken and we can pass some other
	// dimension for chess board as well
	cout << "Total number of solutions = " <<solveNQueens(4).size() << endl;
	cout<< "\nsolutions are as follows" << endl;
	print_board();
	
	return 0;
}
